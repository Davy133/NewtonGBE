#pragma once
#include <common.h>

#define ZERO_FLAG_BYTE_POSITION 7
#define SUBTRACT_FLAG_BYTE_POSITION 6
#define HALF_CARRY_FLAG_BYTE_POSITION 5
#define CARRY_FLAG_BYTE_POSITION 4

struct flags_register
{
	bool zero;
	bool subtract;
	bool half_carry;
	bool carry;
} extern flags_register;

struct registers {
	u8 a;
	u8 f;
	u8 b;
	u8 c;
	u8 d;
	u8 e;
	u8 h;
	u8 l;
	u16 sp;
	u16 pc;
} extern registers;

u8 flags_register_to_byte(struct flags_register flag);
struct flags_register byte_to_flags_register(u8 byte);
