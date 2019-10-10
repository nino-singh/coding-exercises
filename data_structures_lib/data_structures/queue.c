#include "../include/queue.h"

//Add element to back
void queue_add(Queue *q, void *data)
{
  list_append(q->list, data);
}

//Remove element from front and return head of queue
void * queue_remove(Queue *q)
{
  list_remove(q->list, 0);
  return queue_peek(q);
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
