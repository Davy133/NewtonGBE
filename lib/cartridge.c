#include <cartridge.h>

typedef struct{
    char filename[256];
    u32 rom_size;
    u8 *rom;
    rom_header *header;
} cartridge_context;

static cartridge_context cartridge_ctx;

const char *romTypeString[256] = {
	[ROM_PLAIN] = "ROM_PLAIN",
	[ROM_MBC1] = "ROM_MBC1",
	[ROM_MBC1_RAM] = "ROM_MBC1",
	[ROM_MBC1_RAM_BATT] = "ROM_MBC1_RAM_BATT",
	[ROM_MBC2] = "ROM_MBC2",
	[ROM_MBC2_BATTERY] = "ROM_MBC2_BATTERY",
	[ROM_RAM] = "ROM_RAM",
	[ROM_RAM_BATTERY] = "ROM_RAM_BATTERY",
	[ROM_MMM01] = "ROM_MMM01",
	[ROM_MMM01_SRAM] = "ROM_MMM01_SRAM",
	[ROM_MMM01_SRAM_BATT] = "ROM_MMM01_SRAM_BATT",
	[ROM_MBC3_TIMER_BATT] = "ROM_MBC3_TIMER_BATT",
	[ROM_MBC3_TIMER_RAM_BATT] = "ROM_MBC3_TIMER_RAM_BATT",
	[ROM_MBC3] = "ROM_MBC3",
	[ROM_MBC3_RAM] = "ROM_MBC3_RAM",
	[ROM_MBC3_RAM_BATT] = "ROM_MBC3_RAM_BATT",
	[ROM_MBC5] = "ROM_MBC5",
	[ROM_MBC5_RAM] = "ROM_MBC5_RAM",
	[ROM_MBC5_RAM_BATT] = "ROM_MBC5_RAM_BATT",
	[ROM_MBC5_RUMBLE] = "ROM_MBC5_RUMBLE",
	[ROM_MBC5_RUMBLE_SRAM] = "ROM_MBC5_RUMBLE_SRAM",
	[ROM_MBC5_RUMBLE_SRAM_BATT] = "ROM_MBC5_RUMBLE_SRAM_BATT",
	[ROM_POCKET_CAMERA] = "ROM_POCKET_CAMERA",
	[ROM_BANDAI_TAMA5] = "ROM_BANDAI_TAMA5",
	[ROM_HUDSON_HUC3] = "ROM_HUDSON_HUC3",
	[ROM_HUDSON_HUC1] = "ROM_HUDSON_HUC1",
};

const char *licenseeCodeString[256] = {
	[NONE] = "NONE",
	[NINTENDO_R_D1] = "NINTENDO_R_D1",
	[CAPCOM] = "CAPCOM",
	[ELECTRONIC_ARTS] = "ELECTRONIC_ARTS",
	[HUDSON_SOFT] = "HUDSON_SOFT",
	[B_AI] = "B_AI",
	[KSS] = "KSS",
	[POW] = "POW",
	[PCM_COMPLETE] = "PCM_COMPLETE",
	[SAN_X] = "SAN_X",
	[KEMCO_JAPAN] = "KEMCO_JAPAN",
	[SETA] = "SETA",
	[VIACOM] = "VIACOM",
	[NINTENDO] = "NINTENDO",
	[BANDAI] = "BANDAI",
	[OCEAN_ACCLAIM] = "OCEAN_ACCLAIM",
	[KONAMI] = "KONAMI",
	[HECTOR] = "HECTOR",
	[TAITO] = "TAITO",
	[HUDSON] = "HUDSON",
	[BANPRESTO] = "BANPRESTO",
	[UBI_SOFT] = "UBI_SOFT",
	[ATLUS] = "ATLUS",
	[MALIBU] = "MALIBU",
	[ANGEL] = "ANGEL",
	[BULLET_PROOF] = "BULLET_PROOF",
	[IREM] = "IREM",
	[ABSOLUTE] = "ABSOLUTE",
	[ACCLAIM] = "ACCLAIM",
	[ACTIVISION] = "ACTIVISION",
	[AMERICAN_SAMMY] = "AMERICAN_SAMMY",
	[HI_TECH_ENTERTAINMENT] = "HI_TECH_ENTERTAINMENT",
	[LJN] = "LJN",
	[MATCHBOX] = "MATCHBOX",
	[MATTEL] = "MATTEL",
	[MILTON_BRADLEY] = "MILTON_BRADLEY",
	[TITUS] = "TITUS",
	[VIRGIN] = "VIRGIN",
	[LUCASARTS] = "LUCASARTS",
	[OCEAN] = "OCEAN",
	[INFOGRAMES] = "INFOGRAMES",
	[INTERPLAY] = "INTERPLAY",
	[BRODERBUND] = "BRODERBUND",
	[SCULPTURED] = "SCULPTURED",
	[SCI] = "SCI",
	[THQ] = "THQ",
	[ACCOLADE] = "ACCOLADE",
	[MISAWA] = "MISAWA",
	[LOZC] = "LOZC",
	[TOKUMA_SHOTEN_INTERMEDIA] = "TOKUMA_SHOTEN_INTERMEDIA",
	[TSUKUDA_ORIGINAL] = "TSUKUDA_ORIGINAL",
	[CHUNSOFT] = "CHUNSOFT",
	[VIDEO_SYSTEM] = "VIDEO_SYSTEM",
	[OCEAN_ACCLAIM] = "OCEAN_ACCLAIM",
	[VARIE] = "VARIE",
	[YONEZAWA_S_PAL] = "YONEZAWA_S_PAL",
	[KANEKO] = "KANEKO",
	[PACK_IN_SOFT] = "PACK_IN_SOFT",
	[BOTTOM_UP] = "BOTTOM_UP",
	[KONAMI_YU_GI_OH] = "KONAMI_YU_GI_OH"
};

const char *cart_type_name(){
	if(cartridge_ctx.header->cartridge_type > 0x1E){
		return "Unknown";
	}
	return romTypeString[cartridge_ctx.header->cartridge_type];
}
const char *licensee_code_name(){
	if(cartridge_ctx.header->new_licensee_code > 0x33){
		return "Unknown";
	}
	return licenseeCodeString[cartridge_ctx.header->new_licensee_code];
}

bool cartridge_load(char *cartridge){
    FILE *file = fopen(cartridge, "r");

    if(!file){
        printf("Error: Could not open file %s\n", cartridge);
        return false;
    }

    fseek(file, 0, SEEK_END);
    cartridge_ctx.rom_size = ftell(file);
    rewind(file);

    cartridge_ctx.rom = malloc(cartridge_ctx.rom_size);
    fread(cartridge_ctx.rom, 1, cartridge_ctx.rom_size, file);
    fclose(file);

    cartridge_ctx.header = (rom_header *)(cartridge_ctx.rom + 0x100);
    cartridge_ctx.header->title[15] = 0;

    printf("\t Loading %s...\n", cartridge_ctx.header->title);
	printf("\t-------------------------------------------\n");
    printf("\t TYPE			: %2.2X (%s)\n", cartridge_ctx.header->cartridge_type ,cart_type_name());
	printf("\t LIC CODE		: %2.2X (%s)\n", cartridge_ctx.header->new_licensee_code, licensee_code_name());
	printf("\t ROM SIZE		: %d KB\n", 32 << cartridge_ctx.header->rom_size);
	printf("\t RAM SIZE		: %2.2X\n", cartridge_ctx.header->ram_size);
	printf("\t ROM VERS		: %2.2X\n", cartridge_ctx.header->mask_rom_version_number);
	printf("\t-------------------------------------------\n");

	u16 x = 0;
	for(u16 i = 0x134; i < 0x14C; i++){
		x = x - cartridge_ctx.rom[i] - 1;
	}

	printf("\t Checksum		: %2.2X (%s)\n", cartridge_ctx.header->global_checksum, (x & 0xFF) ? "PASSED" : "FAILED");
	return true;
}

void write_data_to_cartridge(u16 address, u8 data){
	NO_IMPL
};

u8 read_data_from_cartridge(u16 address){
	return cartridge_ctx.rom[address];
};
