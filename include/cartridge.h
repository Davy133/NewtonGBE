#pragma once

#include <common.h>

enum romType {
	ROM_PLAIN = 0x00,
	ROM_MBC1 = 0x01,
	ROM_MBC1_RAM = 0x02,
	ROM_MBC1_RAM_BATT = 0x03,
	ROM_MBC2 = 0x05,
	ROM_MBC2_BATTERY = 0x06,
	ROM_RAM = 0x08,
	ROM_RAM_BATTERY = 0x09,
	ROM_MMM01 = 0x0B,
	ROM_MMM01_SRAM = 0x0C,
	ROM_MMM01_SRAM_BATT = 0x0D,
	ROM_MBC3_TIMER_BATT = 0x0F,
	ROM_MBC3_TIMER_RAM_BATT = 0x10,
	ROM_MBC3 = 0x11,
	ROM_MBC3_RAM = 0x12,
	ROM_MBC3_RAM_BATT = 0x13,
	ROM_MBC5 = 0x19,
	ROM_MBC5_RAM = 0x1A,
	ROM_MBC5_RAM_BATT = 0x1B,
	ROM_MBC5_RUMBLE = 0x1C,
	ROM_MBC5_RUMBLE_SRAM = 0x1D,
	ROM_MBC5_RUMBLE_SRAM_BATT = 0x1E,
	ROM_POCKET_CAMERA = 0x1F,
	ROM_BANDAI_TAMA5 = 0xFD,
	ROM_HUDSON_HUC3 = 0xFE,
	ROM_HUDSON_HUC1 = 0xFF,
};

enum licenseeCode {
NONE = 0x00,
NINTENDO_R_D1 = 0x01,
CAPCOM = 0x08,
ELECTRONIC_ARTS = 0x13,
HUDSON_SOFT = 0x18,
B_AI = 0x19,
KSS = 0x20,
POW = 0x22,
PCM_COMPLETE = 0x24,
SAN_X = 0x25,
KEMCO_JAPAN = 0x28,
SETA = 0x29,
VIACOM = 0x30,
NINTENDO = 0x31,
BANDAI = 0x32,
OCEAN_ACCLAIM = 0x33,
KONAMI = 0x34,
HECTOR = 0x35,
TAITO = 0x37,
HUDSON = 0x38,
BANPRESTO = 0x39,
UBI_SOFT = 0x41,
ATLUS = 0x42,
MALIBU = 0x44,
ANGEL = 0x46,
BULLET_PROOF = 0x47,
IREM = 0x49,
ABSOLUTE = 0x50,
ACCLAIM = 0x51,
ACTIVISION = 0x52,
AMERICAN_SAMMY = 0x53,
KONAMI_2 = 0x54,
HI_TECH_ENTERTAINMENT = 0x55,
LJN = 0x56,
MATCHBOX = 0x57,
MATTEL = 0x58,
MILTON_BRADLEY = 0x59,
TITUS = 0x60,
VIRGIN = 0x61,
LUCASARTS = 0x64,
OCEAN = 0x67,
ELECTRONIC_ARTS_2 = 0x69,
INFOGRAMES = 0x70,
INTERPLAY = 0x71,
BRODERBUND = 0x72,
SCULPTURED = 0x73,
SCI = 0x75,
THQ = 0x78,
ACCOLADE = 0x79,
MISAWA = 0x80,
LOZC = 0x83,
TOKUMA_SHOTEN_INTERMEDIA = 0x86,
TSUKUDA_ORIGINAL = 0x87,
CHUNSOFT = 0x91,
VIDEO_SYSTEM = 0x92,
OCEAN_ACCLAIM_2 = 0x93,
VARIE = 0x95,
YONEZAWA_S_PAL = 0x96,
KANEKO = 0x97,
PACK_IN_SOFT = 0x99,
BOTTOM_UP = 0xFF,
KONAMI_YU_GI_OH = 0xA4
};

typedef struct {
    u8 entry_point[4];
    u8 nintendo_logo[48];
    char title[16];
    u16 new_licensee_code;
    u8 sgb_flag;
    u8 cartridge_type;
    u8 rom_size;
    u8 ram_size;
    u8 destination_code;
    u8 old_licensee_code;
    u8 mask_rom_version_number;
    u8 header_checksum;
    u16 global_checksum;
} rom_header;

extern const char *licenseeCodeString[256];
extern const char *romTypeString[256];

bool cartridge_load(char *cartridge);
