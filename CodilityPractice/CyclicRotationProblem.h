#ifndef _CYCLIC_ROTATION_PROBLEM_H
#define _CYCLIC_ROTATION_PROBLEM_H

#ifdef __cplusplus
extern "C" {
#endif

/** Definition of results struct **/
typedef struct
{
  int *A; //Pointer to array of ints
  int N; //Length of array A
}RotateResults;

/** Function Declarations **/
void rightRotateByOne(int A[], int N);
void doCyclicRotation(int A[], int N, int K);

#ifdef __cplusplus
}
#endif
#endif
