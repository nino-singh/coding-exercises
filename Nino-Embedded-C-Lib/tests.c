#include <stdio.h>
#include "NinoEmbeddedLib.h"

int main()
{
  uint32_t x = 0x00000408;
  printf("N: %08x\n",x);
  printf("SET BIT(x,5): %08x \n", _SETBIT(x,5));

  printf("\nN: %08x\n",x);
  printf("CLEAR BIT(x,5): %08x \n", _CLEARBIT(x,5));

  x = 0x00000408;
  printf("\nN: %08x\n",x);
  printf("Number of ones: %d\n",countOnes(x));
}
