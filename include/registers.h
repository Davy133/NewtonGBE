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

struct registers
{
	struct
	{
		union
		{
			struct
			{
				unsigned char f;
				unsigned char a;
			};
			unsigned short af;
		};
	};

	struct
	{
		union
		{
			struct
			{
				unsigned char c;
				unsigned char b;
			};
			unsigned short bc;
		};
	};

	struct
	{
		union
		{
			struct
			{
				unsigned char e;
				unsigned char d;
			};
			unsigned short de;
		};
	};

	struct
	{
		union
		{
			struct
			{
				unsigned char l;
				unsigned char h;
			};
			unsigned short hl;
		};
	};

	unsigned short sp;
	unsigned short pc;

} extern registers;

u8 flags_register_to_byte(struct flags_register flag);
struct flags_register byte_to_flags_register(u8 byte);
