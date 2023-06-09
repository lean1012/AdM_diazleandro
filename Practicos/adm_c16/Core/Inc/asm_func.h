#pragma once

#include <stdint.h>


void asm_svc (void);
uint32_t asm_sum (uint32_t firstOperand, uint32_t secondOperand);

void asm_zeros32 (uint32_t* firstOperand, uint32_t secondOperand);

void asm_zeros16 (uint16_t* firstOperand, uint32_t secondOperand);

void asm_productoEscalar32 (uint32_t* firstOperand, uint32_t* secondOperand, uint32_t d, uint32_t h);

void asm_productoEscalar16 (uint16_t* firstOperand, uint16_t* secondOperand, uint32_t d, uint32_t h);
