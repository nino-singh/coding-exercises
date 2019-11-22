#include "../include/CircularFifo.h"
#include <string.h>
#include <stdlib.h>

/*
* A circular FIFO using an array of bytes to represent elements that
* can be of custom size in the queue
* Last element added is always pointed to by head
* First element added is always pointed to by front
* Remove element at front, then increment front
* Since its an array, first element is at index 0, subsequent
* elements are at front*elementSize in array
* Add element at head, then increment head
* head and front are always an index multiple of elementSize
*/

int fifo_init(CircularFifo_t *fifo, int numElements, int elementSize)
{
  if(numElements > FIFO_MAX_ELEMENTS || elementSize > FIFO_MAX_ELEMENT_SIZE) {
    return -1;
  }

  fifo->totalElements = numElements;
  fifo->elementSize = elementSize;
  fifo->count = 0;
  fifo->rear = 0;
  fifo->front = 0;

  //TODO: Replace malloc with custom static "malloc"
  fifo->buffer = (uint8_t*)malloc(numElements*elementSize);

  if(fifo->buffer == 0) {
    return -1;
  }
  else {
    return 0;
  }
}

int fifo_put(CircularFifo_t *fifo, void *data)
{
  uint16_t rear = fifo->rear;

  //If there's space in the fifo, add element at next rear pos in array
  if(!fifo_isFull(fifo)) {
    memcpy(&fifo->buffer[rear*fifo->elementSize], data, fifo->elementSize);
    //If the element added made fifo full, wrap rear pointer back to beginning
    if(rear >= fifo->totalElements) {
      rear = 0;
    } else {
      rear++;
    }
    //Increment element count
    ++fifo->count;
  }
  //If no space left, set overflow flag and let user decide what to do
  else {
    //Or call the overflow callback routine!
    fifo->ovrFlowFlag = 1;
  }

  return fifo->count;
}

int fifo_get(CircularFifo_t *fifo, void *data)
{
    uint16_t front = fifo->front;
    //If fifo is not empty, retrieve an element at front index of array
    if(!fifo_isEmpty(fifo)) {
      memcpy(data, &fifo->buffer[front*fifo->elementSize], fifo->elementSize);
      if(front >= fifo->totalElements) {
        front = 0;
      } else {
        front++;
      }
      --fifo->count;
      fifo->ovrFlowFlag = 0;
    }
    return fifo->count;
}

int fifo_avail(CircularFifo_t *fifo)
{
  return fifo->count;
}

int fifo_isFull(CircularFifo_t *fifo)
{
  return (fifo->count == fifo->totalElements) ? 1 : 0;
}
int fifo_isEmpty(CircularFifo_t *fifo)
{
  return (fifo->count == 0) ? 1 : 0;
}

void fifo_clear(CircularFifo_t *fifo)
{
  memset(&fifo->buffer[0], 0, fifo->totalElements*fifo->elementSize);
  fifo->front = 0;
  fifo->rear = 0;
  fifo->count = 0;
}

void fifo_desotry(CircularFifo_t *fifo) {

  if(fifo->buffer != NULL) {
    //Replace with custom free function
    free(fifo->buffer);
    fifo->buffer = NULL;
  }
  memset(fifo, 0, sizeof(fifo));
}
