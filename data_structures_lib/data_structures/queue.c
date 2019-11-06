#include "../include/queue.h"

Queue* queue_create(size_t elementSize)
{
  List *list = list_create(elementSize);
  Queue *q = (Queue*)malloc(sizeof(Queue));
  q->list = list;

  return q;
}

//Add element to back
void queue_add(Queue *q, void *data)
{
  list_append(q->list, data);
}

//Remove element from front and return head of queue
void queue_remove(Queue *q)
{
  list_remove(q->list, 0);
}

//Get reference to head of queue
void * queue_peek(Queue *q)
{
  return q->list->head->data;
}

//Get size of queue
int queue_size(Queue *q)
{
  return q->list->listLen;
}
