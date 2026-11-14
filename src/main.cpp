#include <stdio.h>
#include <sys/thread.h>
#include <rsx/rsx.h>
#include <io/pad.h>

// XboxCloudPS3 - Tela inicial

int main() {
    void *host_addr = memalign(1024*1024, 1024*1024);
    gcmContextData *context = rsxInit(0x10000, 1024*1024, host_addr);
    
    printf("XboxCloudPS3 - Carregando...\n");
    printf("Se voce esta vendo isso, o PKG abriu!\n");

    padInfo padinfo;
    padData paddata;
    ioPadInit(7);

    while(1) {
        ioPadGetInfo(&padinfo);
        for(int i = 0; i < 7; i++) {
            if(padinfo.status[i]) {
                ioPadGetData(i, &paddata);
                if(paddata.BTN_START) {
                    return 0;
                }
            }
        }
        sysThreadYield();
    }
    return 0;
}