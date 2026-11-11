import pathlib,struct,logging,lzma,hashlib,json
import pefile,dnfile
logging.disable(logging.CRITICAL)
w=pathlib.Path(__file__).resolve().parent;p=pefile.PE(str(w/'TM-BYPASS.section_decrypted.exe'),fast_load=True);src=p.get_data(0x4e00,10598064*4);mask=0xffffffff;state=2137161620;key=[]
for i in range(16):
 state^=state>>13;state^=(state<<25)&mask;state^=state>>27;key.append(state)
out=bytearray(len(src))
for i,(value,) in enumerate(struct.iter_unpack('<I',src)):
 j=i%16;val=value^key[j];struct.pack_into('<I',out,i*4,val);key[j]^=val
prop=out[0];lc=prop%9;rem=prop//9;lp=rem%5;pb=rem//5;ds=struct.unpack_from('<I',out,1)[0];size=struct.unpack_from('<I',out,5)[0]
print('resource_assembly_expected_size',size,flush=True);assert size<250_000_000
f={'id':lzma.FILTER_LZMA1,'dict_size':ds,'lc':lc,'lp':lp,'pb':pb};data=lzma.LZMADecompressor(format=lzma.FORMAT_RAW,filters=[f]).decompress(out[9:],max_length=size);assert len(data)==size
fp=w/'resource_assembly.dll';fp.write_bytes(data);print('decrypted',len(data),'sha256',hashlib.sha256(data).hexdigest(),flush=True)
dn=dnfile.dnPE(data=data)
for res in dn.net.resources:
 print('resource',res.name,'size',res.size,flush=True)
 if hasattr(res.data,'entries'):
  for e in res.data.entries:
   name=str(e.name);print('entry',name,'type',getattr(e,'type_name',None),'data_type',type(e.data).__name__)
   if 'mdm' in name.lower():
    if isinstance(e.data,bytes):
     (w/('resource_'+name.replace('/','_'))).write_bytes(e.data);print('MDM_bytes',len(e.data),repr(e.data[:16]))
