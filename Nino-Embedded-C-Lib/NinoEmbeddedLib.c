#include "NinoEmbeddedLib.h"

/**
* Count number of 1 bits in 32 bit integer
* Returns number of set bits in integer
*/
uint32_t countOnes(uint32_t n)
{
  uint32_t cnt = 0;
  uint32_t num = n;

  while(num)
  {
    cnt += num & 1;
    num>>=1;
  }

  return cnt;
}

/**
* Get some of two 32-bit integers using bit-wise manipulation
*
*/
uint32_t sumOfTwoInts(uint32_t a, uint32_t b)
{
  return 0;
}
