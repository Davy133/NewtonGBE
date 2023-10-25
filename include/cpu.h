#include <common.h>

struct CPU
{
    u8 current_opcode;
    bool halted;
} extern CPU;

struct instruction
{
    char *dissasembly;
    int args_count;
    void *execute;
} extern const instructions[256];

void cpu_init();
bool cpu_step();

u8 fetch();
void decode(struct CPU *cpu, u8 opcode);
void execute(struct CPU *cpu, struct instruction inst);
