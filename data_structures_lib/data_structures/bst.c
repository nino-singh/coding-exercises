#include "../include/bst.h"
#include "../include/queue.h"
#include "../include/common.h"

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

//Create an empty bst tree
Bstree *create_empty_tree(int (*comp)(const void*, const void *))
{
  Bstree *tree = (Bstree*)malloc(sizeof(Bstree));
  tree->root = NULL;
  tree->numNodes = 0;
  tree->compare = comp;
  return tree;
}

//Create a new bst tree from array of objects
// Bstree *create_tree(KeyValuePair *data, int (*comp)(const void*, const void *))
// {
//   return NULL;
// }

//Insert a new node at a leaf node in the binary search tree
void bstree_insert(Bstree *bst, void *key, void *data)
{
  //Dummy code
  if(bstree_contains(bst, key) != NULL)
  {
    return;
  }

  BstNode *curr = NULL;
  BstNode *parent = NULL;

  if(bst->root == NULL)
  {
      bst->root = create_node(key, data);
      bst->numNodes++;
  }
  else
  {
    curr = bst->root;

    //Search till we hit the correct leaf node to insert at
    while(curr != NULL)
    {
      parent = curr;
      //If curr key is greater than new key, traverse right
      if(bst->compare(curr->key, key))
      {
        curr = curr->left;
      }
      //curr key is less than new key traverse left
      else
      {
        curr = curr->right;
      }
    }

    //if new key is smaller than leaf key, insert as leaf's left child
    if(bst->compare(parent->key, key))
    {
      parent->left = create_node(key, data);
    }
    //if new key is greater than leaf key, insert as leaf's right child
    else {
      parent->right = create_node(key,data);
    }

    bst->numNodes++;

  }
}

//Remove node with given key
void bstree_remove(Bstree *bst, void *key) {}

//Find node with smallest key
BstNode * bstree_getMin(Bstree *bst) {}

//Find node with largest key
BstNode * bstree_getMax(Bstree *bst) {}

//Check if node exists with given key
BstNode * bstree_contains(Bstree *bst, void *key) {return NULL; }

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
void bstree_print(Bstree *bst, void (*printNode)(void *))
{
  Queue *q = queue_create(sizeof(BstNode *));

  BstNode *temp = bst->root;
  queue_add(q, temp);
  KeyValuePair kv;

  while(queue_size(q) > 0)
  {

    //Number of nodes in queue is total nodes in a Level
    int nodeCount = queue_size(q);

    while(nodeCount > 0) {
      temp = (BstNode *) queue_peek(q);
      kv.key = temp->key;
      kv.data = temp->data;

      (*printNode)(&kv);

      if(temp->left != NULL) {
        queue_add(q, temp->left);
      }
      if(temp->right != NULL) {
        queue_add(q, temp->right);
      }
      queue_remove(q);
      nodeCount--;
    }
    printf("\n");
  }
}
