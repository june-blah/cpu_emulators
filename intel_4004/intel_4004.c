#include "intel_4004.h"

static uint8_t r8(Intel4004* cpu, uint8_t address) {
    return cpu->rom[address];
}

static void w8(Intel4004* cpu, uint8_t address, uint8_t src) {
    cpu->rom[address] = src;
}

static uint8_t stack_r8(Intel4004* cpu) {
    // to perform a stack read operation:
    // (1) the pointer is backed up one register.
    // (2) the memory address indicated by the pointer is read.
}

Intel4004* intel_4004_create() {
    Intel4004* cpu = malloc(sizeof(Intel4004));
    if (cpu == NULL) {
        return NULL;
    }
    cpu->rom = NULL; // 5120 bits?
    cpu->instruction_ptr = 0x0;
    cpu->carry_flag = 0x0;
    return cpu;
}

void intel_4004_destroy(Intel4004* cpu) {
    free(cpu->rom);
    free(cpu);
}

void intel_4004_reset(Intel4004* cpu) {

}

void intel_4004_cycle(Intel4004* cpu) {
    const uint8_t low_word = r8(cpu, cpu->instruction_ptr);
    ++cpu->instruction_ptr;
    const uint8_t opr = low_word & 0xf0;
    const uint8_t opa = low_word & 0x0f;
    switch (opcode) {
        case NOP:
            break;
        case JCN: {
            // todo
            // if c_1, c_2, c_3, c_4 is true, then
            //     const uint8_t high_word = r8(cpu, cpu->instruction_ptr);
            //     cpu->instruction_ptr = high_word;
            // else increment instruction_ptr
            break;
        }
        case FIM: {
            const size_t register_pair_idx = opa >> 1;
            const uint8_t high_word = r8(cpu, cpu->instruction_ptr);
            ++cpu->instruction_ptr;
            w8(cpu->index_registers[register_pair_idx], high_word);
            break;
        }
        case FIN_JIN: {
            const size_t register_pair_idx = opa >> 1;
            if opa & 0x1 {
                // jin
                // ? todo
            } else {
                // fin
                w8(cpu->index_registers[register_pair_idx], r8(cpu->index_registers[0]));
            }
            break;
        }
        case JUN: {
            break;
        }
        case JMS: {
            break;
        }
        case INC: {
            uint8_t data = r8(cpu, cpu->index_registers[opa]);
            w8(cpu, cpu->index_registers[opa], ++data);
            break;
        }
        case ISZ: {
            break;
        }
        case ADD:
            break;
        case SUB:
            break;
        case LD:
            break;
        case XCH:
            break;
        case BBL:
            break;
        case LDM:
            break;
        case CLB:
            break;
        case CLC:
            break;
        case IAC:
            break;
        case CMC:
            break;
        case CMA:
            break;
        case RAL:
            break;
        case RAR:
            break;
        case TCC:
            break;
        case DAC:
            break;
        case TCS:
            break;
        case STC:
            break;
        case DAA:
            break;
        case KBP:
            break;
        case DCL:
            break;
    }
}
