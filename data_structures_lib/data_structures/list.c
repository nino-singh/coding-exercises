#include <stdio.h>
#include "../include/list.h"


//Create list
List* list_create(size_t elementSize)
{
  List * list = (List*)malloc(sizeof(List));
  list->elementSize = elementSize;
  list->listLen = 0;
  list->head = NULL;
  list->tail = NULL;
  return list;
}

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
  if((index > list->listLen) || index < 0)
  {
    return;
  }
  else if(index == 0)
  {
    ListNode *headNext = list->head->next;
    ListNode *deleteNode = list->head;
    free(deleteNode);
    list->head = headNext;
    list->listLen--;
  }
  else if(index == list->listLen-1)
  {
    ListNode *deleteNode = list->tail;
    ListNode *iter = list->head;

    for(int i=0; i<index-1; i++)
    {
      iter = iter->next;
    }
    iter->next = NULL;
    list->tail = iter;
    free(deleteNode);
    list->listLen--;
  }
  else
  {
    ListNode *iter = list->head;

    for(int i=0; i<index-1; i++)
    {
      iter = iter->next;
    }
    ListNode *deleteNode = iter->next;
    iter->next = deleteNode->next;
    free(deleteNode);
    list->listLen--;
  }
}

//Return index of the first occurence of the data if its found in list
int list_search(List *list, void *data)
{
  ListNode *iter = list->head;
  int i = 0;
  int index = -1;
  while(iter != NULL && memcmp(iter->data, data, list->elementSize))
  {
    iter = iter->next;
    i++;
  }

  if(iter)
  {
    index = i;
  }
  return index;
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
