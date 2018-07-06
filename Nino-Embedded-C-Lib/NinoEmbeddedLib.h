#ifndef __NINO_EMBEDDED_C_LIBRARY_H__
#define __NINO_EMBEDDED_C_LIBRARY_H__

#ifdef __cplusplus
extern "C"
{
#endif

/** Includes **/
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

/** MACROS for Basic Bit Manipulation Ops **/
#define _SETBIT(X,b)      X|= (1 << b)
#define _CLEARBIT(X,b)    X&= ~(1 << b)
#define _SUBSTRACT(X,Y)   X & ~Y

/** Library Function Declarations **/

//Count number of 1 bits in 32 bit integer
uint32_t countOnes(uint32_t n);

//Get some of two 32-bit integers using bit-wise manipulation
uint32_t sumOfTwoInts(uint32_t a, uint32_t b);


#ifdef __cplusplus
}
#endif

#endif
