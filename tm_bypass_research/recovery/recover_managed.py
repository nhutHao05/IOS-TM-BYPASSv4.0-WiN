"""Create an analysis-only PE with clear user strings and analyst-assigned names.
This file is for decompilation. It must not be run as an application.
"""
import json
import logging
from pathlib import Path
import re
import struct
import unicodedata
import dnfile
from dncil.cil.body.reader import read_method_body_from_bytes

logging.disable(logging.CRITICAL)
w = Path(__file__).resolve().parent.parent
dest = w/'recovery'
source = bytearray((w/'TM-BYPASS.section_decrypted.exe').read_bytes())
pe = dnfile.dnPE(data=source)
streams = {k:bytearray(pe.get_data(v.rva,v.sizeof())) for k,v in pe.net.metadata.streams.items()}
tables = streams[b'#~']
table_rva = pe.net.metadata.streams[b'#~'].rva
table_file = pe.get_offset_from_rva(table_rva)
strings = streams[b'#Strings']
width = 4 if tables[6]&1 else 2
fmt = '<I' if width==4 else '<H'
aliases = {}
records = []
method_names = {
    65:'MainRecovered',207:'CheckRemoteDebuggerPresentRecovered',
    208:'StartAntiAnalysisMonitor',209:'AntiAnalysisMonitorLoop',
    97:'RunMdmOverSsh_Unreferenced',98:'RunMdmBackupRestore',99:'DeleteMdmWorkingDirectory',
    100:'RegisterMdmSerial_Unreferenced',101:'ResolveMdmInfoEndpoint',102:'ResolveMdmManifestEndpoint',
    103:'ExtractMdmToolsArchive',104:'ExtractMdmBackupArchive',105:'RunMdmSetupProcess',
    106:'WriteMdmInfoPlist',107:'WriteMdmManifestPlist',144:'UpdateProgress',146:'EnsureDevicePairing',
    159:'UploadResourceViaScp',160:'ConnectSshOverUsb',162:'MountDeviceFilesystem',176:'ExecuteSshCommand',
    232:'DispatchAuthorizedDeviceOperation',242:'StartMdmWorkflow',265:'QuerySerialAuthorization',
    284:'OnMdmClick',299:'InitializeComponentRecovered',334:'GetMdmToolsArchive',
    338:'GetMdmPlistTemplate',339:'GetMdmBackupArchive',
}
field_names = {0x74:'DeviceIMEI',0x75:'DeviceSerialNumber',0x76:'DeviceProductVersion',
               0x77:'DeviceUDID',0x78:'DeviceProductType',0x79:'UnpopulatedMetadata5',
               0x7a:'UnpopulatedMetadata6',0x8c:'MdmOperationSelected',0xbe:'ButtonMdm',
               0x61:'TemporaryDirectory',0x62:'MdmWorkingDirectory',
               0x6f:'DiagnosticMode',0x70:'ToolVersion',0x71:'ActivationStatus'}
type_names = {13:'ProgramRecovered',20:'DeviceOperationsRecovered',
              22:'DeviceStateRecovered',23:'AntiAnalysisMonitorRecovered',
              24:'MainFormRecovered',29:'ApplicationResourcesRecovered',
              30:'UiResourcesRecovered'}
property_names = {13:'MdmToolsZip',17:'MdmConfigurationTemplate',18:'MdmBackupZip'}


def index_of(row,field):
    return getattr(row.struct,field+'_StringIndex')


def register(row,field,table,rid,name):
    item = getattr(row,field)
    old = str(item)
    if not old or old in ('.ctor','.cctor','<Module>'):
        return
    opaque = any(unicodedata.category(c)=='Cf' for c in old) or any(ord(c)<32 for c in old)
    if field=='TypeName' and not re.fullmatch(r'[A-Za-z_][A-Za-z0-9_]*(?:`[0-9]+)?',old):
        opaque=True
    if (table==6 and rid in method_names or table==4 and rid in field_names
            or table==2 and rid in type_names or table==23 and rid in property_names):
        opaque=True
    if not opaque:
        return
    index = index_of(row,field)
    if index not in aliases:
        new = len(strings)
        encoded = name.encode()+b'\0'
        strings.extend(encoded)
        aliases[index] = (new,name)
    records.append({'table':table,'rid':rid,'field':field,'old_index':index,
                    'new_name':aliases[index][1],'original_name':old})


for tid, fields in [(2,['TypeName','TypeNamespace']),(4,['Name']),(6,['Name']),
                    (8,['Name']),(20,['Name']),(23,['Name']),(42,['Name'])]:
    table = pe.net.mdtables.tables.get(tid)
    if table is None:continue
    for rid,row in enumerate(table.rows,1):
        for field in fields:
            name=f'Recovered_{tid:02x}_{rid:04x}_{field}'
            if tid==6:name=method_names.get(rid,name)
            if tid==4:name=field_names.get(rid,name)
            if tid==23:name=property_names.get(rid,name)
            if tid==2 and field=='TypeName':
                name=type_names.get(rid,name)
                methods={m.row_index for m in row.MethodList}
                if 98 in methods:name='DeviceOperationsRecovered'
                if 299 in methods:name='MainFormRecovered'
            register(row,field,tid,rid,name)

for table in pe.net.mdtables.tables.values():
    for row in table.rows:
        for group in row.struct.__keys__:
            key=group[0]
            if not key.endswith('_StringIndex'):continue
            old=getattr(row.struct,key)
            if old not in aliases:continue
            absolute=row.struct.get_field_absolute_offset(key)
            candidates=[absolute-table_file,absolute-table_rva]
            offset=next((x for x in candidates if 0<=x<=len(tables)-width and struct.unpack_from(fmt,tables,x)[0]==old),None)
            if offset is None:raise ValueError(f'Cannot locate metadata string field {key}')
            struct.pack_into(fmt,tables,offset,aliases[old][0])

# Empty setter parameter names confuse ILSpy's automatic property reconstruction.
# Name only those particular Param rows; never redirect the shared empty string.
value_index=len(strings)
strings.extend(b'value\0')
for sem in pe.net.mdtables.MethodSemantics:
    if not sem.Semantics.msSetter:continue
    for parameter in sem.Method.row.ParamList:
        row=parameter.row
        if row.Sequence!=1 or str(row.Name):continue
        absolute=row.struct.get_field_absolute_offset('Name_StringIndex')
        candidates=[absolute-table_file,absolute-table_rva]
        offset=next((x for x in candidates if 0<=x<=len(tables)-width and struct.unpack_from(fmt,tables,x)[0]==0),None)
        if offset is None:raise ValueError('Cannot locate setter parameter name')
        struct.pack_into(fmt,tables,offset,value_index)
        records.append({'table':8,'rid':parameter.row_index,'field':'Name',
                        'old_index':0,'new_name':'value','original_name':''})


def compressed(n):
    if n<0x80:return bytes([n])
    if n<0x4000:return bytes([(n>>8)|0x80,n&0xff])
    return bytes([(n>>24)|0xc0,(n>>16)&0xff,(n>>8)&0xff,n&0xff])


us=streams[b'#US']
dedup={'':1}
resolved=json.loads((w/'resolved_constants.json').read_text())
by_method={}
for item in resolved:
    if item.get('kind')!='string':raise ValueError('Unexpected constant type')
    by_method.setdefault(item['method'],[]).append(item)
rewritten=0
for rid,items in by_method.items():
    row=pe.net.mdtables.MethodDef.rows[rid-1]
    body=read_method_body_from_bytes(pe.get_data(row.Rva,500000))
    instructions=body.instructions
    positions={i.offset:n for n,i in enumerate(instructions)}
    file_offset=pe.get_offset_from_rva(row.Rva)
    for item in items:
        offset=int(item['il'],16)
        pos=positions[offset]
        previous=pos-1
        while previous>=0 and str(instructions[previous].opcode) in ('br','br.s','nop'):
            previous-=1
        arg=instructions[previous]
        if not str(arg.opcode).startswith('ldc.i4'):raise ValueError('Unexpected decoder argument')
        call=instructions[pos]
        if str(call.opcode)!='call' or call.size!=5:raise ValueError('Unexpected decoder instruction')
        value=item['value']
        if value not in dedup:
            dedup[value]=len(us)
            raw=value.encode('utf-16le')+b'\1'
            us.extend(compressed(len(raw))+raw)
        source[file_offset+arg.offset:file_offset+arg.offset+arg.size]=b'\0'*arg.size
        source[file_offset+offset:file_offset+offset+5]=b'\x72'+struct.pack('<I',0x70000000|dedup[value])
        rewritten+=1
assert rewritten==1444

# Relocate the complete metadata root so the expanded heaps remain contiguous.
metadata_rva=pe.net.struct.MetaDataRva
metadata_file=pe.get_offset_from_rva(metadata_rva)
prefix=bytes(source[metadata_file:metadata_file+36])
assert struct.unpack_from('<H',prefix,34)[0]==5
ordered=[b'#~',b'#Strings',b'#US',b'#GUID',b'#Blob']
header_size=36+sum(8+((len(n)+1+3)&~3) for n in ordered)
header=bytearray(prefix)
payload=bytearray()
for name in ordered:
    while (header_size+len(payload))%4:payload.append(0)
    content=streams[name]
    header.extend(struct.pack('<II',header_size+len(payload),len(content)))
    header.extend((b'#-' if name==b'#~' else name)+b'\0')
    while len(header)%4:header.append(0)
    payload.extend(content)
assert len(header)==header_size
metadata=bytes(header+payload)

align=lambda value,boundary:(value+boundary-1)&~(boundary-1)
section_alignment=pe.OPTIONAL_HEADER.SectionAlignment
file_alignment=pe.OPTIONAL_HEADER.FileAlignment
new_rva=align(max(s.VirtualAddress+max(s.Misc_VirtualSize,s.SizeOfRawData) for s in pe.sections),section_alignment)
raw=align(len(source),file_alignment)
raw_size=align(len(metadata),file_alignment)
new_header=pe.sections[-1].get_file_offset()+40
assert new_header+40<=pe.OPTIONAL_HEADER.SizeOfHeaders
source.extend(bytes(raw-len(source)))
source.extend(metadata)
source.extend(bytes(raw_size-len(metadata)))
struct.pack_into('<8sIIIIIIHHI',source,new_header,b'.meta2\0\0',len(metadata),new_rva,raw_size,raw,0,0,0,0,0x40000040)
struct.pack_into('<H',source,pe.FILE_HEADER.get_field_absolute_offset('NumberOfSections'),len(pe.sections)+1)
struct.pack_into('<I',source,pe.OPTIONAL_HEADER.get_field_absolute_offset('SizeOfImage'),align(new_rva+len(metadata),section_alignment))
struct.pack_into('<I',source,pe.OPTIONAL_HEADER.get_field_absolute_offset('CheckSum'),0)
clr=pe.get_offset_from_rva(pe.OPTIONAL_HEADER.DATA_DIRECTORY[14].VirtualAddress)
struct.pack_into('<II',source,clr+8,new_rva,len(metadata))

out=dest/'TM-BYPASS.analysis-only.exe'
out.write_bytes(source)
(dest/'analyst-name-map.json').write_text(json.dumps(records,ensure_ascii=True,indent=2))
print(json.dumps({'output':str(out),'literal_calls_rewritten':rewritten,'unique_literals':len({x['value'] for x in resolved}),
                  'analyst_aliases':len(aliases),'metadata_bytes':len(metadata),'analysis_only':True}))
