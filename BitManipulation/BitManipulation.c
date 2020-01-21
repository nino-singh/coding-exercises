#include "BitManipulation.h"

//Subtracting one from a decimal number flips all the bits after
//the rightmost set bit including this bit (so everything to the right)
//If you & it with the original number, you unset the last bit
int countSetBits(int n)
{
  int count = 0;

  while(n) {
    n = n & (n-1);
    count++;
  }

  return count;
}

//Add two integers without arithmetic operator
//X^Y gives the sum
//X&Y gives you position of where a carry bit occurs
//To get final sum, shift carry bit by one and add to the sum
//Keep doing this until there are no more carries
int Add(int x, int y) {

  int carry = 0;
  int sum = 0;

  while(y != 0) {
    carry = x & y;
    x = x ^ y;
    y = carry << 1;
  }

  return x;
}

//Find missing number in array of ints 0...to n
//Sum of natural numbers can be expressed as N*(N+1)/2
//Calculate sum of array and subtract from the expected sum,
//this gives you the missing number
int findMissing(int arr[])
{
    //Find total number of elements in array
    int N = *(&arr+1) - arr;
    int expectedSum = N*(N+1)/2;
    int actualSum = 0;

    for(int i = 0; i<N; i++) {
      actualSum+=arr[i];
    }

    return (expectedSum-actualSum);
}

//Find missing number in array of ints 0...to n
//Using bitwise operation, this is worst case O(n) but can be faster
//We know the missing number is in range 0 to n-1.
//XOR all array elements in this range: x1
//XOR all array elements in range 0 to n: x2
//XOR these two together and it returns the difference which is the missing
//number
int findMissingBitwise(int *arr)
{
  int arrSize = *(&arr+1) - arr;
  int missing = arrSize;

  for(int i=0; i<arrSize; i++) {
    missing ^= (i ^ nums[i]);
  }
  return missing;
}

//Reverse bits of a 32-bit unsigned integer
//O(n) solution
uint32_t reverseBits(uint32_t n) {
  uint32_t res = 0;
  int i = sizeof(n) * 8 - 1;

  while(n) {
    res |= (n&1) << i;
    n >>= 1;
    i--;
  }
  return res;
}

//Keep putting set bits of n in reverseNum result until n is zero
// 00000110=n ---> reverseNum = 00000011
//Left shift remaining number of bits in reverseNum, which gives you exact
//reverse
uint32_t reverseBitsFast(uint32_t n) {
  uint32_t totalBits = sizeof(n)*8 - 1;
  uint32_t reverseNum = n;

  //Remove LSB from n
  n>>=1;

  while(n) {

    //Remove MSB from reverseNum
    reverseNum << 1;
    //Add ith bit of n to LSB of reverseNum
    reverseNum |= (n&1)
    n >>= 1;
    totalBits--; //keep track of number of set bits
  }
  reverseNum <<= totalBits;
  return reverseNum; 
}
