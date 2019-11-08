#ifndef __COMMON_UTILITY_H__
#define __COMMON_UTILITY_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdbool.h>

typedef struct KeyValuePair_t {
  void * key;
  void * data;
} KeyValuePair;

void printStringNode(void * s);
void printIntNode(void * num);
void printKeyValueStringNode(void *kv);
void printKeyValueIntNode(void *kv);
int compareInts(const void * a, const void * b);

#ifdef __cplusplus
}
#endif

#endif
