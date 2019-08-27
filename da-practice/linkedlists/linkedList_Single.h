#ifndef _LINKEDLIST_SINGLE_H
#define _LINKEDLIST_SINGLE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stddef.h>

struct Node
{
  int data;
  struct Node *next;
};

/* print nodes of linked list */
void ll_print(struct Node *n);

/* Add node after given node */
void ll_add_after(struct Node *n, int newData);

/* Add node to front of list */
void ll_add(struct Node *n);

/* Remove node */
void ll_remove(struct Node *);

#ifdef __cplusplus
}
#endif
#endif
