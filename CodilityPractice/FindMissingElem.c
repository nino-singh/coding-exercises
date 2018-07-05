#include "FindMissingElem.h"

/**
* Returns the missing number from the integer array of consecutive
* integers.
* Integers are in the range 1 to N+1.
* Sum of integers in range 1 to N = N*(N+1)/2
*/
unsigned int findMissingNumber(unsigned int A[], unsigned int N)
{
  //Find the sum of all integers from 1 to N+1 (includes the missing one)
  unsigned int sum = (N+1)*(N+2)/2;
  //Subtract each integer in the array from the findMissingNumber
  for(int i=0; i<N; i++)
  {
    sum-=A[i];
  }
  //Finally, the reduced amount will be the missing number
  return sum; 
}
