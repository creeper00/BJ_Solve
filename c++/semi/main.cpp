#include <stdio.h>

typedef union {
  float f;
  struct {
    unsigned int mantisa : 23;
    unsigned int exponent : 8;
    unsigned int sign : 1;
  } parts;
} float_cast;

int main(void) {
    float j=-(0.0/0.0);
  float_cast d1 = { .f = j };
  printf("sign = %x\n", d1.parts.sign);
  printf("exponent = %x\n", d1.parts.exponent);
  printf("mantisa = %x\n", d1.parts.mantisa);
}
