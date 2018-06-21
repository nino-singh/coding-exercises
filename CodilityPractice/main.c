#include <stdio.h>
#include <stdlib.h>
#include "CyclicRotationProblem.h"

/** Definitions **/
#define DEFAULT_ARR_SIZE  5

/** Utility Functions **/
void printArray(int A[], int size);

int main()
{
  printf("---- Codility Practice ----\n");
  int A[DEFAULT_ARR_SIZE] = {3,8,9,7,6};
  printArray(A,DEFAULT_ARR_SIZE);

  doCyclicRotation(A,DEFAULT_ARR_SIZE,3);
  printArray(A,DEFAULT_ARR_SIZE);

  return 0;
}

void printArray(int A[], int size)
{
  for(int i=0; i<size; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");
}
