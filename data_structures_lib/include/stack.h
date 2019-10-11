#ifndef __LIFOSTACK_H__
#define __LIFOSTACK_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "list.h"

typedef struct _Stack {
  List *list;
}Stack;

//Push element on to stack
void stack_push(Stack *s, void * data);

//Pop element off stack
void * stack_pop(Stack *s);

//Get size of stack
int stack_size(Stack *s);

#ifdef __cplusplus
}
#endif
#endif
