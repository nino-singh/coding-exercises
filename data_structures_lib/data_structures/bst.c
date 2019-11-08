#include "../include/bst.h"
#include "../include/queue.h"
#include "../include/common.h"

static bool areEqual(Bstree *bst, void *a, void *b);

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
  tree->compareIsGreater = comp;
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

  if(bstree_contains(bst, key))
  {
    return;
  }
  BstNode *curr = NULL;
  BstNode *parent = NULL;

  if(bst->root == NULL)
  {
      bst->root = create_node(key, data);
      bst->numNodes++;
      return;
  }

  curr = bst->root;

  //Search till we hit the correct leaf node to insert at
  while(curr != NULL)
  {
    parent = curr;
    //If curr key is greater than new key, traverse left
    if(bst->compareIsGreater(curr->key, key)){
      curr = curr->left;
    }
    //curr key is less than new key traverse right
    else {
      curr = curr->right;
    }
  }

  //if new key is smaller than leaf key, insert as leaf's left child
  if(bst->compareIsGreater(parent->key, key))
  {
    parent->left = create_node(key, data);
  }
  //if new key is greater than leaf key, insert as leaf's right child
  else {
    parent->right = create_node(key,data);
  }

  bst->numNodes++;

}

//Remove node with given key
/**
* Delete has 3 cases:
* Node has no children, just delete it
* Node has one subtree, make sure to connect the subtree to its parent
* Node has two subtrees, need to find successor and replace deleted node with it
* Successor is the left most (smallest) node in the right subtree
* Predecessor is the right most  (largest) node in the left subtree
**/
void bstree_remove(Bstree *bst, void *key)
{

  if(bstree_contains(bst, key) == NULL) {
    return;
  }

  BstNode *curr = bst->root;

  printf("delete key: %d Curr key: %d\n",(*(int*)key), (*(int*)curr->key));

  while(!areEqual(bst, curr->key, key)) {
    //If key is smaller than curr key, traverse left
    if(bst->compareIsGreater(curr->key, key)) {
      curr = curr->left;
    }
    //If key is greater than current key, traverse right
    else {
      curr = curr->right;
    }
  }

    //Found key
    printf("found key: %d\n", (*(int*)curr->key));
    // Case 1: Delete node no children
    if(curr->left == NULL && curr->right == NULL) {
      free(curr);
    }
    // Case 2: Delete node has left child
    else if(curr->left != NULL && curr->right ==  NULL) {

      BstNode *deleteNode = curr;
      curr = curr->left;
      free(deleteNode);
    }
    // Case 3: Delete node has right child
    else if(curr->left == NULL && curr->right !=  NULL) {
      BstNode *deleteNode = curr;
      curr = curr->right;
      free(deleteNode);
    }
    //Case 4: Delete node has two children, find node's successor, and replace
    else if(curr->right != NULL && curr->left != NULL) {
      BstNode *deleteNode = curr;
      Bstree rSubTree;
      rSubTree.root = curr->right;
      BstNode *successor = bstree_getMin(&rSubTree);
      curr = successor;
      free(deleteNode);
    }
    bst->numNodes--;

}

//Find node with smallest key
BstNode * bstree_getMin(Bstree *bst)
{
    BstNode *curr = bst->root;
    BstNode *parent = NULL;
    while(curr != NULL) {
      parent = curr;
      curr = curr->left;
    }
    return parent;
}

//Find node with largest key
BstNode * bstree_getMax(Bstree *bst) {}

//Check if node exists with given key
BstNode * bstree_contains(Bstree *bst, void *key)
{
  if(bst->root == NULL){
    return NULL;
  }

  BstNode *curr = bst->root;

  while(curr != NULL) {
    //Check if key is smaller than curr node key
    if(bst->compareIsGreater(curr->key, key)) {
      curr = curr->left;
    //If key is not smaller or greater than curr key, its equal
    } else if(!bst->compareIsGreater(curr->key, key)  \
                && !bst->compareIsGreater(key, curr->key)) {
      return curr;
    //Otherwise key is bigger than current key
    } else {
      curr = curr->right;
    }
  }

  return curr;
}

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
  if(bst->root == NULL) {
    return;
  }

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

static bool areEqual(Bstree *bst, void *a, void *b) {

  if(!bst->compareIsGreater(a, b)  \
              && !bst->compareIsGreater(b, a))
    return true;
  else
    return false;
}
