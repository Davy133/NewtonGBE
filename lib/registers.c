#include <registers.h>

struct registers registers;
struct flags_register flags;

u8 flags_register_to_byte(struct flags_register flag){
    return  (flag.zero ? 1 : 0) << ZERO_FLAG_BYTE_POSITION |
            (flag.subtract ? 1 : 0) << SUBTRACT_FLAG_BYTE_POSITION |
            (flag.half_carry ? 1 : 0) << HALF_CARRY_FLAG_BYTE_POSITION |
            (flag.carry ? 1 : 0) << CARRY_FLAG_BYTE_POSITION;
}

struct flags_register byte_to_flags_register(u8 byte){
    bool zero = ((byte >> ZERO_FLAG_BYTE_POSITION) & 0b1) != 0;
    bool subtract = ((byte >> SUBTRACT_FLAG_BYTE_POSITION) & 0b1) != 0;
    bool half_carry = ((byte >> HALF_CARRY_FLAG_BYTE_POSITION) & 0b1) != 0;
    bool carry = ((byte >> CARRY_FLAG_BYTE_POSITION) & 0b1) != 0;

    struct flags_register flag;
    flag.zero = zero;
    flag.subtract = subtract;
    flag.half_carry = half_carry;
    flag.carry = carry;

    return flag;
}
