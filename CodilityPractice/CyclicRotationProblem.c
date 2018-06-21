#include "CyclicRotationProblem.h"

/** Helper Function Declarations **/
//static void leftRotateByOne(int A[], int N);

/**
* Solution to the Cyclic Rotation Problem.
* Do left rotation by 1, K times
*/
void doCyclicRotation(int A[], int N, int K)
{
  for(int k = 0; k<K; k++)
  {
    rightRotateByOne(A,N);
  }
}

/**
* Left Rotate all elements by one
*/
void rightRotateByOne(int A[], int N)
{
  //Save last element of array
  int tempElement = A[N-1];
  int i;
  for(i=N-1; i>0; i--)
  {
    A[i] = A[i-1];
  }

  //Put last element in first position
  A[0] = tempElement;

}
