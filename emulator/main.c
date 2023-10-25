#include <cartridge.h>
#include <databus.h>
#include <registers.h>
#include <cpu.h>

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("Usage: %s <ROM file>\n", argv[0]);
        return 1;
    }

    if(!cartridge_load(argv[1])){
        printf("Error: Could not load ROM file %s\n", argv[1]);
        return 1;
    }

    printf("[!] Cartridge loaded successfully.\n");
    printf("[!] Initializing CPU...\n");
    cpu_init();
    printf("[!] CPU initialized successfully.\n");
    printf("[!] Starting CPU...\n");
    while(cpu_step());
}
