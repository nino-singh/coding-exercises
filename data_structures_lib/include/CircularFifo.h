#ifndef __CIRCULAR_FIFO_H__
#define __CIRCULAR_FIFO_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define FIFO_MAX_ELEMENTS       1024
#define FIFO_MAX_ELEMENT_SIZE   256

typedef struct CircularFifo {
  uint16_t count;
  uint16_t totalElements;
  uint8_t  elementSize;
  uint8_t *buffer;
  uint16_t rear;
  uint16_t front;

  //Set this flag if fifo is full and we try and add new element
  uint8_t ovrFlowFlag;
} CircularFifo_t;

int fifo_init(CircularFifo_t *fifo, int numElements, int elementSize);
int fifo_put(CircularFifo_t *fifo, void *data);
int fifo_get(CircularFifo_t *fifo, void *data);
int fifo_avail(CircularFifo_t *fifo);
int fifo_isFull(CircularFifo_t *fifo);
int fifo_isEmpty(CircularFifo_t *fifo);
void fifo_clear(CircularFifo_t *fifo);
void fifo_destroy(CircularFifo_t *fifo);

#ifdef __cplusplus
}
#endif
#endif
