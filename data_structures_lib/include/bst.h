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
  int numNodes;
  size_t elementSize;
  bool (*compare)(const void*, const void*);
}Bstree;

//Create a new bst node
BstNode *create_node(void *key, void*data);

//Insert a new node in the binary search tree
void bstree_insert(Bstree *bst, void *key, void *data);

//Remove node with given key
void bstree_remove(Bstree *bst, void *key);

//Find node with smallest key
BstNode * bstree_getMin(Bstree *bst);

//Find node with largest key
BstNode * bstree_getMax(Bstree *bst);

//Check if node exists with given key
BstNode * bstree_contains(Bstree *bst, void *key);

//Check if node exists with given key
bool bstree_isFull(Bstree *bst);

//Check if node exists with given key
bool bstree_isBalanced(Bstree *bst);

//Get height of the tree
bool bstree_getHeight(Bstree *bst);

//Return number of nodes in tree
int bstree_size(Bstree *bst);

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
