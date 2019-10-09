#include <stdio.h>
#include "../include/list.h"


//Get the data of an item in the list specified by index
void * list_get(List *list, int index)
{
  ListNode *iter = list->head;

  if((index > list->listLen) || index < 0)
  {
    return NULL;
  }
  else
  {
    int i = 0;
    while(iter != NULL && i != index)
    {
      iter = iter->next;
      i++;
    }
  }
  return iter->data;
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
  ListNode *node = (ListNode *)malloc(sizeof(ListNode));
  node->data = data;
  node->next = NULL;

  if(list->head == NULL)
  {
    list->head = node;
    list->tail = node;
  }
  else
  {
      node->next = list->head;
      list->head = node;
  }
  list->listLen++;
}

//Insert item at index position in the list
void list_insert(List *list, void *data, int index)
{
  printf("%d\n", list->listLen);
  if((index > list->listLen) || index < 0)
  {
    return;
  }
  else if(index == 0)
  {
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    node->next = list->head;
    list->head = node;
    list->listLen++;
  }
  else if(index == list->listLen-1)
  {
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    node->next = NULL;
    list->tail->next = node;
    list->tail = node;
    list->listLen++;
  }
  else
  {
    int i=0;
    ListNode *iter = list->head;
    while(iter != NULL && i != index-1)
    {
      iter = iter->next;
      i++;
    }
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    ListNode *oldNext = iter->next;
    iter->next = node;
    node->next = oldNext;
    list->listLen++;
  }

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

//Return the number of elements in the list
int list_size(List *list)
{
  return list->listLen;
}

//Print nodes in the list
void list_print(List *list, void (*printFn)(void *))
{
  ListNode *node = list->head;
  int i = 0;
  while(node != NULL)
  {
    printf("(%d): ", i);
    (*printFn)(node->data);
    printf("\n");
    node = node->next;
    i++;
  }

}
