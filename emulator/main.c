#include <cartridge.h>
int main(int argc, char *argv[]){
    bool result = cartridge_load(argv[1]);
    if(result){
        printf("ROM loaded successfully.\n");
    }
}
