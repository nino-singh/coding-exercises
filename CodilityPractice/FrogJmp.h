#ifndef __FROG_JUMP_H__
#define __FROG_JUMP_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
/**
* Find minimum number of jumps to get from position X to a
* position equal to or greater than Y.
*/
unsigned int findMinJumps(unsigned int X, unsigned int Y, unsigned int D);


#ifdef __cplusplus
}
#endif

#endif
