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
void btree_insert(BtNode *root, void *key, void *data);

//Remove node with given key
void btree_remove(BtNode *root, void *key);

//Find node with given key an return data
void *btree_retrieve(BtNode *root, void *key);

//Check if node exists with given key
bool btree_contains(BtNode *root, void *key);

//Return number of nodes in tree
int btree_size(BtNode *root);

//Return true if tree is empty
bool btree_isEmpty(BtNode *root);

//
void btree_preorder_print(BtNode *node, void (*printNode)(void *));

//
void btree_postorder_print(BtNode *node, void (*printNode)(void *));

//
void btree_inorder_print(BtNode *node, void (*printNode)(void *));

void btree_levelorder_print(BtNode *node, void (*printNode)(void *));


#ifdef __cplusplus
}
#endif

#endif
