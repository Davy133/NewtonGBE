#include <databus.h>
#include <cartridge.h>

// Start    End	    Description	Notes
// 0000	    3FFF	16 KiB ROM bank 00	From cartridge, usually a fixed bank
// 4000	    7FFF	16 KiB ROM Bank 01~NN	From cartridge, switchable bank via mapper (if any)
// 8000 	9FFF	8 KiB Video RAM (VRAM)	In CGB mode, switchable bank 0/1
// A000	    BFFF	8 KiB External RAM	From cartridge, switchable bank if any
// C000 	CFFF	4 KiB Work RAM (WRAM)
// D000	    DFFF	4 KiB Work RAM (WRAM)	In CGB mode, switchable bank 1~7
// E000	    FDFF	Mirror of C000~DDFF (ECHO RAM)	Nintendo says use of this area is prohibited.
// FE00	    FE9F	Object attribute memory (OAM)
// FEA0 	FEFF	Not Usable	Nintendo says use of this area is prohibited
// FF00 	FF7F	I/O Registers
// FF80 	FFFE	High RAM (HRAM)
// FFFF 	FFFF	Interrupt Enable register (IE)


void write_data(u16 address, u8 data)
{
    if (address < 0x8000)
    {
        printf("[+] Writing to cartridge...\n");
        write_data_to_cartridge(address, data);
    }
}

u8 read_data(u16 address)
{
    if (address < 0x8000)
    {
        printf("[+] Reading from cartridge...\n");
        return read_data_from_cartridge(address);
    }
}
