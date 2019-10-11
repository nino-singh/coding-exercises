#ifndef __STACKTESTS_H__
#define __STACKTESTS_H__

#include "include/common.h"
#include "include/stack.h"

void run_stack_tests(void)
{
  Stack *stack = (Stack*)malloc(sizeof(Stack));
  List *list = (List*)malloc(sizeof(List));

  list->head = NULL;
  list->tail = NULL;
  list->elementSize = sizeof(int);
  list->listLen = 0;

  stack->list = list;

  printf("--- Push onto Stack ----\n");
  int numbers[] = {1,2,3,4,5,6,7,8,9,10};

  stack_push(stack, &numbers[0]);
  list_print(stack->list, printIntNode);

  printf("--- Push onto Stack ----\n");
  stack_push(stack, &numbers[2]);
  list_print(stack->list, printIntNode);

  printf("--- Push onto Stack ----\n");
  stack_push(stack, &numbers[3]);
  list_print(stack->list, printIntNode);

  printf("--- Push onto Stack ----\n");
  stack_push(stack, &numbers[4]);
  list_print(stack->list, printIntNode);

  printf("--- Pop off Stack ----\n");
  stack_pop(stack);
  list_print(stack->list, printIntNode);

  printf("--- Pop off Stack ----\n");
  stack_pop(stack);
  list_print(stack->list, printIntNode);

  printf("--- Stack size ---\n");
  printf("Size: %d\n", stack_size(stack));
}
#endif
