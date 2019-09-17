#ifndef _LINKEDLIST_SINGLE_H
#define _LINKEDLIST_SINGLE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

/* print nodes of linked list */
void ll_print(struct Node *n);

/* Add node after given node */
void ll_insert(struct Node **node_ref, int newData);

/* Add node to front of list */
void ll_prepend(struct Node **head_ref, int newData);

/* Add node to end of list */
void ll_append(struct Node **head_ref, int newData);

/* Remove node after given node in list */
void ll_remove(struct Node **head_ref, int key);

/* Remove node at given position in list */
void ll_removeAt(struct Node **head_ref, int pos);

/* Get number of nodes in the list */
int ll_length(struct Node **head_ref);

/* Get Nth node from end of list */
int ll_getNthFromEnd(struct Node **head_ref, int n);

/* Get node in middle of the list */
int ll_getMiddle_v1(struct Node **head_ref);

/* Get node in middle of the list */
int ll_getMiddle_v2(struct Node **head_ref);

/* Get node in middle of the list */
int ll_getFreqofNode(struct Node **head_ref, int key);

/* Detect if loop is present in the linked list */
unsigned int ll_isLoopPresent(struct Node **head_ref);


#ifdef __cplusplus
}
#endif
#endif
