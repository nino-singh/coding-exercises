#include "../include/bst.h"

//Create a new bst node
BstNode *create_node(void *key, void*data)
{
  BstNode *newNode = (BstNode *)malloc(sizeof(BstNode));
  newNode->key = key;
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

//Insert a new node in the binary search tree
void bstree_insert(Bstree *bst, void *key, void *data) {}

//Remove node with given key
void bstree_remove(Bstree *bst, void *key) {}

//Find node with smallest key
BstNode * bstree_getMin(Bstree *bst) {}

//Find node with largest key
BstNode * bstree_getMax(Bstree *bst) {}

//Check if node exists with given key
BstNode * bstree_contains(Bstree *bst, void *key) {}

//Check if node exists with given key
bool bstree_isFull(Bstree *bst) {return false;}

//Check if node exists with given key
bool bstree_isBalanced(Bstree *bst) {return false;}

//Get height of the tree
bool bstree_getHeight(Bstree *bst) {return false;}

//Return number of nodes in tree
int bstree_size(Bstree *bst) {return 1;}

//
void bstree_preorder(Bstree *bst) {}

//
void bstree_postorder(Bstree *bst) {}

//
void bstree_inorder(Bstree *bst) {}

//Print nodes of binary search tree
void bstree_print(Bstree *bst, void (*printNode)(void *)) {}
