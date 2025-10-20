#ifndef INTEL_4004_H_
#define INTEL_4004_H_

#include <stdint.h>
#include <stdlib.h>

// Intel 4004, Single Chip 4-Bit, P-Channel Microprocessor
// Reference 1: https://datasheets.chipdb.org/Intel/MCS-4/datashts/intel-4004.pdf
// Reference 2: https://codeabbey.github.io/heavy-data-1/msc-4-asm-manual-1973.pdf

// instruction cycle, 8 clock periods

// 1 word instruction, 8-bit, 1 instruction cycle
// high_nibble, OPR field (opcode)
// low_nibble, OPA field (modifier)

// 2 word instruction, 16-bit, 2 instruction cycles
// low_word,
//     high_nibble, OPR field (opcode)
//     low_nibble, OPA field (modifier)
// high_word, address

// OPR always fetched before OPA during M_1 and M_2 times respectively.

typedef enum Intel4004Mnemonic {
    NOP = 0x00,
    JCN = 0x01,
    FIM = 0x02,
    FIN_JIN = 0x03, // FIN, JIN
    JUN = 0x04,
    JMS = 0x05,
    INC = 0x06,
    ISZ = 0x07,
    ADD = 0x08,
    SUB = 0x09,
    LD = 0x0a,
    XCH = 0x0b,
    BBL = 0x0c,
    LDM = 0x0d,
    CLB = 0xf0,
    CLC = 0xf1,
    IAC = 0xf2,
    CMC = 0xf3,
    CMA = 0xf4,
    RAL = 0xf5,
    RAR = 0xf6,
    TCC = 0xf7,
    DAC = 0xf8,
    TCS = 0xf9,
    STC = 0xfa,
    DAA = 0xfb,
    KBP = 0xfc,
    DCL = 0xfd,
} Intel4004Mnemonic;

typedef struct Intel4004 {
    uint8_t* rom;
    uint8_t instruction_ptr;
    // registers
    uint8_t index_registers[16]; // 16 registers, each 4-bit
    uint16_t stack_registers[3]; // 3 registers, each 12-bit
    uint8_t accumulator; // 4-bit
    uint8_t carry_flag; // 1-bit
} Intel4004;

Intel4004* intel_4004_create();
void intel_4004_destroy(Intel4004* cpu);
void intel_4004_reset(Intel4004* cpu);
void intel_4004_cycle(Intel4004* cpu);

#endif // INTEL_4004_H_
