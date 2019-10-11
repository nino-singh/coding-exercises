#include "../include/stack.h"

//Push element on to stack
void stack_push(Stack *s, void * data)
{
  list_prepend(s->list, data);
}

//Pop element off stack
void * stack_pop(Stack *s)
{
  list_remove(s->list, 0);
  return s->list->head; 
}

//Get size of stack
int stack_size(Stack *s)
{
  return s->list->listLen;
}
