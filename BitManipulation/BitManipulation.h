#ifndef __BIT_MANIPULATION_H__
#define __BIT_MANIPULATION_H__

/**
* Common bitwise hacks to know
* AND two numbers checks even or odd
* Right shift by 2 -->division by 2
* Left shift by 2 -->multiply by 2
* n & (n-1): Selects and unsets last bit
* Subtracting 1 from a number flips all bits to the right
* of the rightmost set bit (including this bit)
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

//Count number of set bits in binary representation of given number
int countSetBits(int n);

//Add two integers without arithmetic operator
int Add(int x, int y);

//Find missing number in array of ints 0...to n
//Using mathematics concept of sum of natural numbers
//Always takes O(n)
int findMissing(int arr[]);

//Find missing number in array of ints 0...to n
//Using bitwise operation, this is worst case O(n) but can be faster
int findMissingBitwise(int *arr);

//Reverse bits of a 32-bit unsigned integer
//O(n) solution
uint32_t reverseBits(uint32_t n);

//Reverse bits of a 32-bit unsigned integer
//O(log n) solution
uint32_t reverseBitsFast(uint32_t n)

//Find out if number is odd
int isOddNumber(int n);

//Swap endianness
int swapEndianness(int n);

//Detect if system is little endian or big endian 
bool isLittleEndian(void);

//Compute bitwise and of all numbers in range m to n inclusive
//0<=m <= n <= 2147483647
int rangeBitwiseAnd(int n);


#ifdef __cplusplus
}
#endif



#endif
