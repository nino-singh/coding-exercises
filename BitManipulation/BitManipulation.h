#ifndef __BIT_MANIPULATION_H__
#define __BIT_MANIPULATION_H__

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


#ifdef __cplusplus
}
#endif



#endif
