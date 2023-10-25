
#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

#define NO_IMPL                              \
    {                                        \
        fprintf(stderr, "Not implemented."); \
        exit(1);                             \
    }
