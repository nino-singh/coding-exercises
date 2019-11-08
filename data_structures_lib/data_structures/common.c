#include "../include/common.h"

void printStringNode(void * s)
{
  printf("%s ,",(char *) s);
}

void printIntNode(void * num)
{
  printf("%d ,",*((int *)num));
}

void printKeyValueStringNode(void *kv)
{
  KeyValuePair *keyValue = (KeyValuePair*)kv;
  printf("(%d, %s) ", *((int*)keyValue->key), (char*)keyValue->data);
}

int compareInts(const void * a, const void * b)
{
  return (*(int *)a > *(int *)b ? 1 : 0);
}
