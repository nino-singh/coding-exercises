#include "FrogJmp.h"

#define DEBUG 0

/**
* Find minimum number of jumps to get from position X to a
* position equal to or greater than Y.
*/
unsigned int findMinJumps(unsigned int X, unsigned int Y, unsigned int D)
{
  unsigned int distance = Y-X;

#if DEBUG
  printf("Dist: %f\n", distance);
#endif

  double jumps = ceil((double)distance/D);

#if DEBUG
  printf("Jumps: %f\n",jumps);
#endif

  return (unsigned int) jumps;

}
