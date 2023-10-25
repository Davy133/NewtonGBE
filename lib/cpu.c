#include <cpu.h>
#include <registers.h>
#include <databus.h>

struct CPU CPU_context;

u8 fetch()
{
    return read_data(registers.pc++);
}

void decode(struct CPU *cpu, u8 opcode)
{
    switch (opcode)
    {
    default:
        fprintf(stderr, "[FATAL ERROR] Unknown opcode: 0x%02X\n", opcode);
        exit(1);
    }
}

void cpu_init()
{
    CPU_context.halted = false;
    registers.pc = 0x100;
}

bool cpu_step()
{
    if (CPU_context.halted)
    {
        return false;
    }

    CPU_context.current_opcode = fetch();
    decode(&CPU_context, CPU_context.current_opcode);
    return true;
}
