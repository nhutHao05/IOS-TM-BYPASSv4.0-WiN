/* Offline contract probes: the original DLL and serialization code execute.
 * Only the separate usbmuxd DLL's final transport boundaries are replaced.
 */
#include <windows.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef void *plist_t;
typedef void (WINAPI *from_xml_t)(const char *,uint32_t,plist_t *);
typedef void (WINAPI *to_xml_t)(plist_t,char **,uint32_t *);
typedef void (WINAPI *free_plist_t)(plist_t);
typedef plist_t (WINAPI *array_item_t)(plist_t,uint32_t);
typedef void (WINAPI *uint_value_t)(plist_t,uint64_t *);
typedef int (WINAPI *request_t)(void *,const char *,const char *,const char *,plist_t);
typedef int (WINAPI *message_t)(void *,const char *,plist_t);
typedef int (WINAPI *status_t)(void *,int,const char *,plist_t);
typedef int (WINAPI *raw_t)(void *,char *,uint32_t,uint32_t *);

enum { REQUEST, MESSAGE, STATUS, SEND_RAW, RECEIVE_RAW };
struct probe_case {
    const char *id;
    int api,client;
    const char *name,*target,*source,*xml;
    int status;
    const char *status_text;
    int raw_mode,null_data,zero_length,null_bytes;
};
#include "cases.generated.h"

static to_xml_t to_xml;
static const struct probe_case *active;
static unsigned captures,raw_calls,raw_offset;
static char raw_capture[128];
static char frame[65536];
static unsigned frame_size;

static void save_plist(plist_t node,const char *suffix)
{
    char *xml=0,path[256];
    uint32_t length=0;
    FILE *file;
    to_xml(node,&xml,&length);
    if(!xml) ExitProcess(61);
    snprintf(path,sizeof(path),"/output/%s%s.xml",active->id,suffix);
    file=fopen(path,"wb");
    if(!file || fwrite(xml,1,length,file)!=length) ExitProcess(62);
    fclose(file);
    /* libplist owns this allocation; do not free it with the Unix CRT. */
}

static int WINAPI raw_service(void *client,char *data,uint32_t length,uint32_t *count)
{
    unsigned n;
    if(!client || !data || !count || length>64) ExitProcess(64);
    raw_calls++;
    /* mode 0: partial transfers until complete; mode 1: EOF immediately;
     * mode 2: a partial transfer followed by EOF; mode 3: positive counts
     * together with a service error, testing which signal the caller uses. */
    n=length>2 ? 2 : length;
    if(active->raw_mode==1 || (active->raw_mode==2 && raw_calls>1))n=0;
    if(raw_offset+n>sizeof(raw_capture)) ExitProcess(65);
    if(active->api==RECEIVE_RAW) {
        unsigned i;
        for(i=0;i<n;i++)data[i]="ABCDEFG"[raw_offset+i];
    }
    if(n)memcpy(raw_capture+raw_offset,data,n);
    raw_offset+=n;
    *count=n;
    return (!n || active->raw_mode==3) ? -5 : 0;
}

static int WINAPI mux_send(int fd,char *data,uint32_t length,uint32_t *count)
{
    if(fd!=1234 || !data || !count)ExitProcess(66);
    if(active->api==SEND_RAW)return raw_service((void *)1,data,length,count);
    raw_calls++;
    if(frame_size+length>sizeof(frame))ExitProcess(67);
    memcpy(frame+frame_size,data,length);frame_size+=length;*count=length;
    return 0;
}
static int WINAPI mux_receive(int fd,char *data,uint32_t length,uint32_t *count)
{
    if(fd!=1234 || active->api!=RECEIVE_RAW)ExitProcess(68);
    return raw_service((void *)1,data,length,count);
}

static int patch(HMODULE module,const char *name,void *replacement)
{
    unsigned char *entry=(unsigned char *)GetProcAddress(module,name);
    unsigned char bytes[12]={0x48,0xb8,0,0,0,0,0,0,0,0,0xff,0xe0};
    DWORD old;
    FILE *audit=fopen("/output/patches.log","ab");
    if(!entry || !VirtualProtect(entry,sizeof(bytes),PAGE_EXECUTE_READWRITE,&old)) {
        if(audit){fprintf(audit,"FAILED %s error=%lu\n",name,(unsigned long)GetLastError());fclose(audit);}
        return 0;
    }
    *(uint64_t *)(bytes+2)=(uint64_t)replacement;
    memcpy(entry,bytes,sizeof(bytes));
    FlushInstructionCache(GetCurrentProcess(),entry,sizeof(bytes));
    VirtualProtect(entry,sizeof(bytes),old,&old);
    if(audit){fprintf(audit,"OK %s address=%p\n",name,entry);fclose(audit);}
    return 1;
}

int main(void)
{
    HMODULE device,plist,mux;
    request_t request;
    message_t message;
    status_t status;
    raw_t send_raw,receive_raw;
    from_xml_t from_xml;
    from_xml_t from_bin;
    array_item_t array_item;
    uint_value_t uint_value;
    free_plist_t free_plist;
    void *chain[8],*empty;
    FILE *results;
    unsigned i,j;
    SetErrorMode(SEM_FAILCRITICALERRORS|SEM_NOGPFAULTERRORBOX|SEM_NOOPENFILEERRORBOX);
    SetDllDirectoryW(L"Z:\\input");
    plist=LoadLibraryW(L"Z:\\input\\plist.dll");
    device=LoadLibraryW(L"Z:\\input\\imobiledevice.dll");
    mux=LoadLibraryW(L"Z:\\input\\usbmuxd.dll");
    if(!plist || !device || !mux)return 20;
    from_xml=(from_xml_t)GetProcAddress(plist,"plist_from_xml");
    from_bin=(from_xml_t)GetProcAddress(plist,"plist_from_bin");
    array_item=(array_item_t)GetProcAddress(plist,"plist_array_get_item");
    uint_value=(uint_value_t)GetProcAddress(plist,"plist_get_uint_val");
    to_xml=(to_xml_t)GetProcAddress(plist,"plist_to_xml");
    free_plist=(free_plist_t)GetProcAddress(plist,"plist_free");
    request=(request_t)GetProcAddress(device,"mobilebackup2_send_request");
    message=(message_t)GetProcAddress(device,"mobilebackup2_send_message");
    status=(status_t)GetProcAddress(device,"mobilebackup2_send_status_response");
    send_raw=(raw_t)GetProcAddress(device,"mobilebackup2_send_raw");
    receive_raw=(raw_t)GetProcAddress(device,"mobilebackup2_receive_raw");
    if(!from_xml || !from_bin || !array_item || !uint_value || !to_xml || !free_plist || !request || !message || !status || !send_raw || !receive_raw)return 21;
    { FILE *audit=fopen("/output/patches.log","wb");if(audit)fclose(audit); }
    if(!patch(mux,"usbmuxd_send",(void *)&mux_send)
       || !patch(mux,"usbmuxd_recv",(void *)&mux_receive)
       || !patch(mux,"usbmuxd_recv_timeout",(void *)&mux_receive))return 22;
    for(i=0;i<8;i++)chain[i]=HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,4096);
    for(i=0;i<7;i++)*(void **)chain[i]=chain[i+1];
    /* Windows x64 upstream idevice_connection_private:
     * device pointer, connection type, padding, fd-as-pointer, ssl pointer. */
    *(uint32_t *)((char *)chain[4]+8)=1; /* CONNECTION_USBMUXD */
    *(void **)((char *)chain[4]+16)=(void *)1234;
    *(void **)((char *)chain[4]+24)=0;
    empty=HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,4096);
    results=fopen("/output/results.jsonl","wb");if(!results)return 23;
    for(i=0;i<sizeof(cases)/sizeof(cases[0]);i++) {
        plist_t options=0;
        void *client;
        uint32_t bytes=0xa5a5a5a5;
        uint64_t status_uint64=0;
        char buffer[64]={0};
        char hex[256]={0};
        int rc;
        active=&cases[i];captures=raw_calls=raw_offset=frame_size=0;memset(raw_capture,0,sizeof(raw_capture));
        client=active->client==0 ? 0 : active->client==1 ? empty : chain[0];
        if(active->xml) {
            from_xml(active->xml,(uint32_t)strlen(active->xml),&options);
            if(!options)ExitProcess(24);
        }
        if(active->api==REQUEST)rc=request(client,active->name,active->target,active->source,options);
        else if(active->api==MESSAGE)rc=message(client,active->name,options);
        else if(active->api==STATUS)rc=status(client,active->status,active->status_text,options);
        else {
            raw_t fn=active->api==SEND_RAW ? send_raw : receive_raw;
            if(active->api==SEND_RAW)memcpy(buffer,"ABCDEFG",7);
            rc=fn(client,active->null_data ? 0 : buffer,active->zero_length ? 0 : 7,
                active->null_bytes ? 0 : &bytes);
        }
        if(options) { save_plist(options,"__input_after");free_plist(options); }
        if(frame_size) {
            char path[256];FILE *wire;
            snprintf(path,sizeof(path),"/output/%s.frame",active->id);
            wire=fopen(path,"wb");if(!wire || fwrite(frame,1,frame_size,wire)!=frame_size)ExitProcess(69);
            fclose(wire);captures=1;
            if(active->api==STATUS && frame_size>4) {
                plist_t root=0;
                from_bin(frame+4,frame_size-4,&root);
                if(!root)ExitProcess(70);
                uint_value(array_item(root,1),&status_uint64);
                free_plist(root);
            }
        }
        for(j=0;j<raw_offset;j++)snprintf(hex+2*j,sizeof(hex)-2*j,"%02x",(unsigned char)raw_capture[j]);
        fprintf(results,"{\"id\":\"%s\",\"return_code\":%d,\"captures\":%u,\"raw_calls\":%u,\"bytes\":%u,\"data_hex\":\"%s\",\"status_uint64\":%llu}\n",
                active->id,rc,captures,raw_calls,bytes,hex,(unsigned long long)status_uint64);
        fflush(results);
    }
    fclose(results);
    return 0;
}
