#include <windows.h>
#include <stdint.h>

typedef void *plist_t;
typedef plist_t (WINAPI *new_dict_t)(void);
typedef plist_t (WINAPI *new_bool_t)(uint8_t);
typedef plist_t (WINAPI *new_string_t)(const char *);
typedef void (WINAPI *dict_set_t)(plist_t,const char *,plist_t);
typedef void (WINAPI *to_xml_t)(plist_t,char **,uint32_t *);
typedef int (WINAPI *request_t)(void *,const char *,const char *,const char *,plist_t);
static to_xml_t to_xml;

static void WINAPI capture_binary_serialization(plist_t node,char **out,uint32_t *out_size)
{
    char *xml=0;
    uint32_t size=0;
    DWORD written=0;
    HANDLE file;
    to_xml(node,&xml,&size);
    file=CreateFileW(L"Z:\\output\\restore_wire.xml",GENERIC_WRITE,0,0,CREATE_ALWAYS,0,0);
    if(file==INVALID_HANDLE_VALUE || !xml) ExitProcess(31);
    WriteFile(file,xml,size,&written,0);
    CloseHandle(file);
    /* Stop before any transport or fake client connection can be used. */
    ExitProcess(written==size ? 0 : 32);
}

int main(void)
{
    HMODULE plist,device;
    new_dict_t new_dict;
    new_bool_t new_bool;
    new_string_t new_string;
    dict_set_t dict_set;
    request_t request;
    unsigned char *entry;
    unsigned char patch[12]={0x48,0xb8,0,0,0,0,0,0,0,0,0xff,0xe0};
    DWORD old_protection;
    plist_t options;
    void *chain[8];
    unsigned i;
    int rc;
    SetErrorMode(SEM_FAILCRITICALERRORS|SEM_NOGPFAULTERRORBOX|SEM_NOOPENFILEERRORBOX);
    SetDllDirectoryW(L"Z:\\input");
    plist=LoadLibraryW(L"Z:\\input\\plist.dll");
    device=LoadLibraryW(L"Z:\\input\\imobiledevice.dll");
    if(!plist || !device) return 20;
    new_dict=(new_dict_t)GetProcAddress(plist,"plist_new_dict");
    new_bool=(new_bool_t)GetProcAddress(plist,"plist_new_bool");
    new_string=(new_string_t)GetProcAddress(plist,"plist_new_string");
    dict_set=(dict_set_t)GetProcAddress(plist,"plist_dict_set_item");
    to_xml=(to_xml_t)GetProcAddress(plist,"plist_to_xml");
    entry=(unsigned char *)GetProcAddress(plist,"plist_to_bin");
    request=(request_t)GetProcAddress(device,"mobilebackup2_send_request");
    if(!new_dict || !new_bool || !new_string || !dict_set || !to_xml || !entry || !request) return 21;
    *(uint64_t *)(patch+2)=(uint64_t)(void *)&capture_binary_serialization;
    if(!VirtualProtect(entry,sizeof(patch),PAGE_EXECUTE_READWRITE,&old_protection)) return 22;
    for(i=0;i<sizeof(patch);i++) entry[i]=patch[i];
    FlushInstructionCache(GetCurrentProcess(),entry,sizeof(patch));
    options=new_dict();
    dict_set(options,"RestoreSystemFiles",new_bool(0));
    dict_set(options,"RestoreDontCopyBackup",new_bool(1));
    dict_set(options,"RestorePreserveSettings",new_bool(1));
    dict_set(options,"Password",new_string("mdm"));
    for(i=0;i<8;i++) chain[i]=HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,4096);
    for(i=0;i<7;i++) *(void **)chain[i]=chain[i+1];
    rc=request(chain[0],"Restore","OFFLINE-LAB-UDID","OFFLINE-LAB-UDID",options);
    return rc ? 40 : 41;
}
