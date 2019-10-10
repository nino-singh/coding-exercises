#include "../include/common.h"

void printStringNode(void * s)
{
  printf("%s ,",(char *) s);
}

void printIntNode(void * num)
{
  printf("%d ,",*((int *)num));
}
