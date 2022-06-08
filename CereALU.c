#include "CereALU.h"

uint32_t Add(uint32_t a, uint32_t b) {
  return a + b;
}

uint32_t Subtract(uint32_t a, uint32_t b) {
  return a - b;
}

uint32_t Multiply(uint32_t a, uint32_t b) {
  return a * b;
}

uint32_t Divide(uint32_t a, uint32_t b) {
  return a / b;
}

uint32_t AddFPGA() { return 0; }
uint32_t SubtractFPGA() { return 0; }
uint32_t MultiplyFPGA() { return 0; }
uint32_t DivideFPGA() { return 0; }
