#include <stdint.h>

#ifndef __CEREALU_H__
#define __CEREALU_H__

uint32_t Add(uint32_t a, uint32_t b);
uint32_t Subtract(uint32_t a, uint32_t b);
uint32_t Multiply(uint32_t a, uint32_t b);
uint32_t Divide(uint32_t a, uint32_t b);
uint32_t AddFPGA();
uint32_t SubtractFPGA();
uint32_t MultiplyFPGA();
uint32_t DivideFPGA();

#endif
