#ifndef INTEL_4004_H_
#define INTEL_4004_H_

#include <stdint.h>

// Intel 4004, Single Chip 4-Bit, P-Channel Microprocessor
// https://datasheets.chipdb.org/Intel/MCS-4/datashts/intel-4004.pdf

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
    NOP,
    JCN,
    FIM,
    FIN,
    JIN,
    JUN,
    JMS,
    INC,
    INS,
    ADD,
    SUB,
    LD,
    XCH,
    BBL,
    LDM,
    CLB,
    CLC,
    IAC,
    CMC,
    CMA,
    RAL,
    RAR,
    TCC,
    DAC,
    TCS,
    STC,
    DAA,
    KBP,
    DCL,
} Intel4004Mnemonic;

typedef struct Intel4004 {
} Intel4004;

void intel_4004_reset(Intel4004* cpu);

#endif // INTEL_4004_H_
