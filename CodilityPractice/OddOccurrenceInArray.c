#include "OddOccurrenceInArray.h"

#define DEBUG_VERBOSE 1

/** Helper Functions **/
static int maxValue(int A[],int N);
static void printArray(int A[], int N);

/**
* First Solution Attempt
* O(n) Time complexity
* Requires extra space for storing frequency of elements
* Returns value of the element with odd number of occurences.
*/
int findOddOccurrencesInArray1(int A[], int N)
{
  //Initialize array to hold number of occurrences of each value
  //Size of array should be set to max value in Array since the array values
  //will be used as indexes into the count array
  int max = maxValue(A,N);

  #ifdef DEBUG_VERBOSE
    printf("findOddOccurrencesInArray: max value is %d\n",max);
  #endif
  int cntSize = max + 1;

  int *cntArr = (int*)malloc(sizeof(int)*cntSize);
  memset(cntArr,0,sizeof(int)*cntSize);

  for(int i=0; i<N; i++)
  {
    cntArr[A[i]] = cntArr[A[i]] + 1;
  }

  #ifdef DEBUG_VERBOSE
    printf("findOddOccurrencesInArray: Cnt Array: ");
    printArray(cntArr,cntSize);
  #endif

  int rem = 0;
  int oddOccurrenceValue = 0;

  for(int i=0; i<cntSize; i++)
  {
    if(cntArr[i] % 2 > 0)
    {
      oddOccurrenceValue = i;
      break;
    }
  }
  free(cntArr);
  return oddOccurrenceValue;
}

/**
* Second Solution Attempt
* Do bitwise XOR of all the elements
* XOR two same elements is 0. XOR element with 0, you get back
* the element.
* Time Complexity O(n)
* Space Complexity O(1)
*/
int findOddOccurrencesInArray2(int A[], int N)
{
  int result = 0;
  for(int i=0; i<N; i++)
  {
    result = result ^ A[i];
  }
  return result; 
}

/**
* Find max value in integer array
*/
static int maxValue(int A[],int N)
{
  int max = 0;

  for(int i=0; i<N; i++)
  {
      if(A[i] > max)
      {
        max = A[i];
      }
  }

  return max;
}

/**
* Prints elements in the Array
*/
static void printArray(int A[], int N)
{
  for(int i=0; i<N; i++)
  {
    printf("%d ",A[i]);
  }
  printf("\n");
}
