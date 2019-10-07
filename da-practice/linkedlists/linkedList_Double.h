#ifndef _DOUBLE_LINKED_LIST_H
#define _DOUBLE_LINKED_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>

struct DNode {

  struct DNode *prev;
  struct DNode *next;
  int data;

};

/* print nodes of linked list */
void lld_print(struct DNode *n);

/* Add node after given node */
void lld_insertAfter(struct DNode **node_ref, int newData);

/* Add node before given node */
void lld_insertBefore(struct DNode **node_ref, int newData);

/* Add node to front of list */
void lld_prepend(struct DNode **head_ref, int newData);

/* Add node to end of list */
void lld_append(struct DNode **head_ref, int newData);
//
// /* Remove node after given node in list */
// void ll_remove(struct Node **head_ref, int key);
//
// /* Remove node at given position in list */
// void ll_removeAt(struct Node **head_ref, int pos);
//
// /* Get number of nodes in the list */
// int ll_length(struct Node **head_ref);


#ifdef __cplusplus
}
#endif
#endif
