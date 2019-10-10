#ifndef __FIFOQUEUE_H__
#define __FIFOQUEUE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "list.h"

typedef struct _Queue {
  List *list;
}Queue;

//Add element to back
void queue_add(Queue *q, void * data);

//Remove element from front
void* queue_remove(Queue *q);

//Get reference to head of queue
void * queue_peek(Queue *q);

//Get size of queue
int queue_size(Queue *q);


#ifdef __cplusplus
}
#endif
#endif
