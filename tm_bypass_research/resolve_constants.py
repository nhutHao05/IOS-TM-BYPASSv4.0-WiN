import pathlib,dnfile,logging,struct,json,re
from dncil.cil.body.reader import read_method_body_from_bytes
logging.disable(logging.CRITICAL)
w=pathlib.Path(__file__).resolve().parent;dn=dnfile.dnPE(str(w/'TM-BYPASS.section_decrypted.exe'));data=(w/'constants.bin').read_bytes();mask=0xffffffff
bodies={i:read_method_body_from_bytes(dn.get_data(m.Rva,500000)) for i,m in enumerate(dn.net.mdtables.MethodDef.rows,1) if m.Rva}
params={}
for i in range(8,13):
 ins=bodies[i].instructions
 maths=[x.operand for x in ins if str(x.opcode)=='ldc.i4']
 params[i]=(maths[0]&mask,maths[1]&mask)
print('decoder_parameters',params)
def decode_int(ins):
 op=str(ins.opcode)
 if op=='ldc.i4.m1':return -1
 if op in ('ldc.i4','ldc.i4.s'):return ins.operand
 if op.startswith('ldc.i4.'):
  try:return int(op.split('.')[-1])
  except ValueError:return None
 return None
specs={i:(s.Method.row_index,bytes(s.Instantiation.value)) for i,s in enumerate(dn.net.mdtables.MethodSpec.rows,1)}
def resolve(ins,prev):
 if str(ins.opcode)!='call' or not hasattr(ins.operand,'value') or ins.operand.value>>24!=0x2b:return None
 spec=specs.get(ins.operand.value&0xffffff)
 if not spec or spec[0] not in params:return None
 val=decode_int(prev)
 if val is None:return None
 mult,xor=params[spec[0]];val=((val*mult)&mask)^xor;off=(val&0x3fffffff)<<2
 if off+4>len(data):return {'error':'out_of_range','offset':off}
 if spec[1]==b'\x0a\x01\x0e':
  n=struct.unpack_from('<I',data,off)[0]
  if off+4+n>len(data):return {'error':'bad_length','offset':off}
  return {'kind':'string','offset':hex(off),'value':data[off+4:off+4+n].decode('utf8')}
 return {'kind':'other','offset':hex(off),'signature':spec[1].hex(),'raw_u32':struct.unpack_from('<I',data,off)[0]}
def ref(t):
 if not hasattr(t,'value'):return str(t)
 table=t.value>>24;idx=t.value&0xffffff
 try:
  row=dn.net.mdtables.tables[table].rows[idx-1];name=str(getattr(row,'Name',getattr(row,'TypeName','')))
  if hasattr(row,'Class'):
   cr=row.Class.row;name=str(getattr(cr,'TypeName',''))+'.'+name
  if name and all(ord(c)>127 for c in name):name='[obfuscated]'
  return hex(t.value)+' '+name.encode('unicode_escape').decode()
 except Exception:return str(t)
lines=[];resolved=[]
for idx,body in bodies.items():
 m=dn.net.mdtables.MethodDef.rows[idx-1];lines.append(f'\nMETHOD {idx} TOKEN {0x6000000+idx:#x} RVA {m.Rva:x} size {body.size}')
 for j,ins in enumerate(body.instructions):
  prev_index=j-1
  while prev_index>=0 and str(body.instructions[prev_index].opcode) in ('br','br.s','nop'): prev_index-=1
  d=resolve(ins,body.instructions[prev_index]) if prev_index>=0 else None
  if d:resolved.append({'method':idx,'il':hex(ins.offset),**d})
  lines.append(f'{ins.offset:04x} {str(ins.opcode):18s} {json.dumps(d,ensure_ascii=False) if d else ref(ins.operand)}')
(w/'resolved_cil.txt').write_text('\n'.join(lines));(w/'resolved_constants.json').write_text(json.dumps(resolved,ensure_ascii=False,indent=2))
print('resolved_calls',len(resolved),'errors',sum('error'in x for x in resolved))
for x in resolved:
 if x.get('kind')=='string' and re.search(r'mdm|CloudConfig|ConfigurationProfiles',x['value'],re.I):
  print(json.dumps({**x,'value':x['value'][:350]},ensure_ascii=False))
