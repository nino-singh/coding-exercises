#ifndef __QUEUETESTS_H__
#define __QUEUETESTS_H__

#include "include/common.h"
#include "include/queue.h"

void run_queue_tests(void)
{
  Queue *passengerQueue = (Queue *)malloc(sizeof(Queue));
  List *list = (List*)malloc(sizeof(List));

  list->head = NULL;
  list->tail = NULL;
  list->elementSize = sizeof(int);
  list->listLen = 0;

  passengerQueue->list = list;

  printf("--- Add passenger to queue ---\n");
  int numbers[] = {1,2,3,4,5};
  queue_add(passengerQueue, &numbers[0]);
  list_print(passengerQueue->list, printIntNode);
  printf("--- Add passenger to queue ---\n");
  queue_add(passengerQueue, &numbers[1]);
  list_print(passengerQueue->list, printIntNode);
  printf("--- Add passenger to queue ---\n");
  queue_add(passengerQueue, &numbers[2]);
  list_print(passengerQueue->list, printIntNode);
  printf("--- Add passenger to queue ---\n");
  queue_add(passengerQueue, &numbers[3]);
  list_print(passengerQueue->list, printIntNode);
  printf("--- Add passenger to queue ---\n");
  queue_add(passengerQueue, &numbers[4]);
  list_print(passengerQueue->list, printIntNode);

  printf("--- Remove passenger from queue ---\n");
  queue_remove(passengerQueue);
  list_print(passengerQueue->list, printIntNode);

  printf("--- Remove passenger from queue ---\n");
  queue_remove(passengerQueue);
  list_print(passengerQueue->list, printIntNode);

  printf("---- Peek Queue ----\n");
  printf("Peek: %d\n" , (*(int*)queue_peek(passengerQueue)));

  printf("---- Queue size ---\n");
  printf("Size: %d\n", passengerQueue->list->listLen);

}

#endif
