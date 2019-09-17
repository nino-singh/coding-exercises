#include "linkedList_Single.h"

/* print nodes of linked list */
void ll_print(struct Node *n)
{
  printf("---- Linked List ----\n");
  while(n != NULL)
  {
    printf("LL node: %d\n", n->data);
    n = n->next;
  }
}

/* Add node after given node */
void ll_insert(struct Node **node_ref, int newData)
{
  struct Node *afterNode = *node_ref;
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = newData;
  newNode->next = afterNode->next;
  afterNode->next = newNode;
}

/* Add node to front of list
* Make the head pointer, point to new node which is now n1
*/
void ll_prepend(struct Node **head_ref, int newData)
{
  struct Node *n = (struct Node *)malloc(sizeof(struct Node));

  //Check if list is empty
  if(*head_ref == NULL)
  {
    n->data = newData;
    n->next = NULL;
    *head_ref = n;
  }
  else
  {
    n->data = newData;
    n->next = *head_ref;
    *head_ref = n;
  }
}

/* Add node to end of list */
void ll_append(struct Node **head_ref, int newData)
{
  struct Node *n = (struct Node*)malloc(sizeof(struct Node));

  if(*head_ref == NULL)
  {
    n->data = newData;
    n->next = NULL;
    *head_ref = n;
  }
  else
  {
    struct Node *iter = *head_ref;
    while(iter->next != NULL)
    {
      iter = iter->next;
    }
    n->data = newData;
    n->next = NULL;
    iter->next = n;
  }
}

/* Remove node after given node in list */
void ll_remove(struct Node **head_ref, int key)
{
  struct Node *curr = *head_ref;
  struct Node *prev = *head_ref;

  if(curr != NULL && curr->data == key)
  {
    *head_ref = curr->next;
    free(curr);
    return;
  }

  while(curr != NULL && curr->data != key)
  {
    prev = curr;
    curr=curr->next;
  }

  //Traversed entire list and key wasn't found, return
  if(curr == NULL)
  {
    return;
  }
  prev->next = curr->next;
  free(curr);

}

/* Remove node at given position in list */
void ll_removeAt(struct Node **head_ref, int pos)
{
  struct Node *curr = *head_ref;
  struct Node *prev = *head_ref;

  if(pos == 0)
  {
      *head_ref = curr->next;
      free(curr);
      return;
  }
  for(int i = 0; i < pos; i++)
  {
    prev = curr;
    curr = curr->next;
  }

  if(curr == NULL)
  {
    return;
  }

  prev->next = curr->next;
  free(curr);

}
