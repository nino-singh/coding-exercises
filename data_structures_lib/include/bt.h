#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct _btNode {
  void *data;
  struct _btNode *left;
  struct _btNode *right;
} BtNode;

//Create a new bst node
BtNode *btree_create_node(void*data);

//Insert a new node in the binary search tree
void btree_insert(BtNode *root, void *data);

//Remove node with given key
void btree_remove(BtNode *root, void *data);

//
void btree_preorder_print(BtNode *node, void (*printNode)(void *));

void btree_postorder_print(BtNode *node, void (*printNode)(void *));

void btree_inorder_print(BtNode *node, void (*printNode)(void *));

void btree_levelorder_print(BtNode *node, void (*printNode)(void *));


#ifdef __cplusplus
}
#endif

#endif
