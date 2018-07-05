#include "TapeEquilibrium.h"

/*
* Find minimum difference between the sum of two parts
* of an array. Choose divider such that difference is minimized.
*
* O(n^2) Complexity solution. Brute Force
*/
int findMinDifferenceOfParts(int A[], int N)
{
  //Simplest way is to brute-force, compute all possible differences
  //Set P to first index
  //Sum up all other elements and keep track of which is min difference
  int leftPart = 0;
  int rightPart = 0;
  unsigned int P = 0;
  int minDiff = 100000000;
  int currDiff = 0;

  for(int j = 1; j<N; j++)
  {
    P = j;
    leftPart = 0;
    rightPart = 0;

    for(int i=0; i<P; i++)
    {
      leftPart += A[i];
    }

    for(int i = P; i<N; i++)
    {
      rightPart += A[i];
    }

    currDiff = abs(leftPart -  rightPart);

    if(currDiff < minDiff)
    {
      minDiff = currDiff;
    }
  }
  return minDiff;
}
