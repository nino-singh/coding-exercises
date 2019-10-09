#ifndef __LINKEDLIST__H__
#define __LINKEDLIST__H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/** List node definition **/
typedef struct _ListNode {
  void *data;
  struct _ListNode * next;
}ListNode;

/** Single linked list definition **/
typedef struct _List {
  int listLen;
  int elementSize;
  ListNode *head;
  ListNode *tail;

} List;

/*** List interface functions***/

//Get the data of an item in the list specified by index
void * list_get(List *list, int index);

//Add item to end of the list
void list_append(List *list, void *data);

//Add item to front of the list
void list_prepend(List *list, void *data);

//Insert item at index position in the list
void list_insert(List *list, void *data, int index);

//Remove item at index position
void list_remove(List *list, int index);

//Return first occurence of the data if its found in list
int list_search(List *list, void *data);

//Return the number of elements in the list in bytes
int list_size(List *list);

typedef enum
{
  LIST_STRINGS,
  LIST_CHAR,
  LIST_INT32,
  LIST_INT16,
  LIST_FLOAT,
  LIST_DOUBLE
}ListType;

//Print nodes in the list
void list_print(List *list, void (*printFn)(void *));

#ifdef __cplusplus
}
#endif
#endif
