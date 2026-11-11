import pathlib,struct,json,logging
import pefile,dnfile
from dncil.cil.body.reader import read_method_body_from_bytes
logging.disable(logging.CRITICAL)
w=pathlib.Path(__file__).resolve().parent;b=bytearray((w/'extracted/TM-BYPASSv4.0/TM-BYPASS.exe').read_bytes());p=pefile.PE(data=b,fast_load=True)
mask=0xffffffff
z,x,c,v=65208925,789691915,(-2030534319)&mask,1160778982
target=(-1863954902)&mask; encrypted=None
for s in p.sections:
 a,bb=struct.unpack('<II',s.Name);n=(a*bb)&mask
 if n==target: encrypted=s;continue
 if not n:continue
 for (word,) in struct.iter_unpack('<I',s.get_data()):
  t=((z^word)+x+c*v)&mask;z=x;x=c;x=v;v=t
assert encrypted is not None
rotr=lambda a,n:((a>>n)|(a<<(32-n)))&mask
key=[];tmp=[]
for i in range(16):
 key.append(v);tmp.append(x);z=rotr(x,5);x=rotr(c,3);c=rotr(v,7);v=rotr(z,11)
for i in range(16):
 key[i]=((key[i]^tmp[i]) if i%3==0 else key[i]*tmp[i] if i%3==1 else key[i]+tmp[i])&mask
start=encrypted.PointerToRawData;end=start+encrypted.SizeOfRawData
for i,off in enumerate(range(start,end,4)):
 enc=struct.unpack_from('<I',b,off)[0];j=i&15;val=enc^key[j];struct.pack_into('<I',b,off,val);key[j]=((key[j]^val)+1035675673)&mask
clr=p.get_offset_from_rva(p.OPTIONAL_HEADER.DATA_DIRECTORY[14].VirtualAddress);meta=p.get_offset_from_rva(struct.unpack_from('<I',b,clr+8)[0]);struct.pack_into('<H',b,meta+34,5)
out=w/'TM-BYPASS.section_decrypted.exe';out.write_bytes(b)
dn=dnfile.dnPE(data=b);ok=0;fail=0;unknown=0
for m in dn.net.mdtables.MethodDef.rows:
 if not m.Rva:continue
 try:
  body=read_method_body_from_bytes(dn.get_data(m.Rva,200000));ok+=1;unknown+=sum('UNKNOWN' in str(i.opcode) for i in body.instructions)
 except Exception: fail+=1
print(json.dumps({'encrypted_section':encrypted.Name.hex(),'section_bytes':encrypted.SizeOfRawData,'methods_parsed':ok,'methods_failed':fail,'unknown_opcodes':unknown}))
