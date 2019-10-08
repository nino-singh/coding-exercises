#include <stdio.h>
#include "../include/list.h"


//Get the data of an item in the list specified by index
void * list_get(List *list, int index)
{

}

//Add item to end of the list
void list_append(List *list, void *data)
{
  ListNode *node = (ListNode*)malloc(sizeof(ListNode));
  node->data = data;
  node->next = NULL;

  if(list->listLen == 0)
  {
    list->head = node;
    list->tail = node;
  }
  else {
    list->tail->next = node;
    list->tail = node;
  }

  list->listLen++;
}

//Add item to front of the list
void list_prepend(List *list, void *data)
{

}

//Insert item at index position in the list
void list_insert(List *list, int index)
{

}

//Remove item at index position
void list_remove(List *list, int index)
{

}

//Return first occurence of the data if its found in list
int list_search(List *list, void *data)
{
  return -1;
}

//Return the number of elements in the list in bytes
int list_size(List *list)
{
  return -1;
}

//Print nodes in the list
void list_print(List *list, void (*printFn)(void *))
{
  ListNode *node = list->head;
  while(node != NULL)
  {
    (*printFn)(node->data);
    printf("\n");
    node = node->next;
  }

}
