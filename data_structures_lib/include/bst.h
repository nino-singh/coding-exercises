#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "queue.h"

typedef struct _bstNode {
  void *key;
  void *data;
  struct _bstNode *left;
  struct _bstNode *right;
}BstNode;

typedef struct _bstree {
  BstNode *root;
  int size;
}Bstree;

//Create a new bst node
BstNode *create_node(void *key, void*data);

//Insert a new node in the binary search tree
void bstree_insert(Bstree *bst, void *key, void *data);

//Remove node with given key
void bstree_remove(Bstree *bst, void *key);

//Find node with given key an return data
void *bstree_retrieve(Bstree *bst, void *key);

//Check if node exists with given key
bool bstree_contains(Bstree *bst, void *key);

//Return number of nodes in tree
int bstree_size(Bstree *bst);

//Return true if tree is empty
bool bstree_isEmpty(Bstree *bst);

//
void bstree_preorder(Bstree *bst);

//
void bstree_postorder(Bstree *bst);

//
void bstree_inorder(Bstree *bst);

//Print nodes of binary search tree
void bstree_print(Bstree *bst, void (*printNode)(void *));

#ifdef __cplusplus
}
#endif

#endif
