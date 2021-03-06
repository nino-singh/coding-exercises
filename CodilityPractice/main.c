#include <stdio.h>
#include <stdlib.h>
#include "CyclicRotationProblem.h"
#include "OddOccurrenceInArray.h"
#include "FrogJmp.h"
#include "FindMissingElem.h"
#include "TapeEquilibrium.h"

/** Definitions **/
#define DEFAULT_ARR_SIZE  5

/** Utility Functions **/
void printArray(int A[], int size);

int main()
{
  printf("---- Codility Practice ----\n");


  printf("**** Cyclic Rotation ****\n");
  printf("--- TEST 1 ----\n");
  int A[DEFAULT_ARR_SIZE] = {3,8,9,7,6};
  printArray(A,DEFAULT_ARR_SIZE);


  doCyclicRotation(A,DEFAULT_ARR_SIZE,3);
  printArray(A,DEFAULT_ARR_SIZE);

  printf("--- TEST 2 ----\n");
  int A2[4] = {1,2,3,4};
  printArray(A2,4);

  doCyclicRotation(A2,4,4);
  printArray(A2,4);

  printf("--- TEST 3 ----\n");
  int A3[3] = {0,0,0};
  printArray(A3,3);

  doCyclicRotation(A3,3,1);
  printArray(A3,3);


  printf("**** Odd Occurences in Array ****\n");
  int A4[7] = {9,3,9,3,9,7,9};
  printArray(A4,7);
  printf("Solution 1: %d\n", findOddOccurrencesInArray1(A4,7));
  printf("Solution 2: %d\n",findOddOccurrencesInArray2(A4,7));

  printf("\n**** Minimum number of Jumps from X to Y ****\n");
  printf("Min Jumps: %d\n",findMinJumps(10,85,30));

  printf("\n**** Find missing number ****\n");
  int A5[4] = {2, 3, 1, 5};
  printf("Missing num is: %d\n", findMissingNumber(A5,4));

  printf("\n**** Find Min Difference between Parts ****\n");
  int A6[5] = {3, 1, 2, 4,3};
  printf("Min Diff is: %d\n", findMinDifferenceOfParts(A6,5));

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
