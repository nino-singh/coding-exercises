#include "linkedList_Double.h"


/* print nodes of linked list */
void lld_print(struct DNode *n)
{
  struct DNode *iter = n;
  while(n != NULL)
  {
    printf("%d ", n->data);
    n = n->next;
  }
  printf("\n");
}

/* Add node after given node */
void lld_insertAfter(struct DNode **node_ref, int newData)
{
  struct DNode* afterNode = *node_ref;
  struct DNode* afterNext = afterNode->next;

  struct DNode *newNode = (struct DNode*)malloc(sizeof(struct DNode));
  newNode->data = newData;
  afterNode->next = newNode;
  newNode->prev = afterNode;
  newNode->next = afterNext;
  afterNext->prev = newNode;

}

/* Add node to front of list */
void lld_prepend(struct DNode **head_ref, int newData)
{
  struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));

  if(*head_ref == NULL)
  {
    *head_ref = newNode;
    newNode->prev = NULL;
    newNode->next = NULL;
    newNode->data = newData;
  }
  else
  {
    newNode->next = *head_ref;
    newNode->prev = NULL;
    newNode->data = newData;
    *head_ref = newNode;
  }
}

/* Add node to end of list */
void lld_append(struct DNode **head_ref, int newData)
{
  struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));

  if(*head_ref == NULL)
  {
    *head_ref = newNode;
    newNode->prev = NULL;
    newNode->next = NULL;
    newNode->data = newData;
  }
  else
  {
    struct DNode* node = NULL;
    node = *head_ref;
    while(node->next != NULL)
    {
      node = node->next;
    }

    struct DNode * last = node;

    newNode->data = newData;
    newNode->prev = last;
    newNode->next = NULL;
    last->next = newNode;

  }
}
