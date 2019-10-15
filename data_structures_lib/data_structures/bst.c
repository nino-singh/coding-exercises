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
void bstree_insert(Bstree *bst, void *key, void *data)
{

}

//Remove node with given key
void bstree_remove(Bstree *bst, void *key)
{

}

//Find node with given key an return data
void * bstree_retrieve(Bstree *bst, void *key)
{
  return NULL;
}

//Check if node exists with given key
bool bstree_contains(Bstree *bst, void *key)
{
  return false;
}

//Return number of nodes in tree
int bstree_size(Bstree *bst)
{
  return -1;
}

//Return true if tree is empty
bool bstree_isEmpty(Bstree *bsst)
{
  return false;
}

//
void bstree_preorder(Bstree *bst)
{

}

//
void bstree_postorder(Bstree *bst)
{

}

//
void bstree_inorder(Bstree *bst)
{

}

//Print nodes in level order traveseral
void bstree_print(Bstree *bst, void (*printNode)(void *))
{
  if(bst->root == NULL) return;

  Queue q;
  List list;

  q.list = &list;
  BstNode *root = bst->root;
  queue_add(&q, root);

  while(queue_size(&q) > 0)
  {
    int nodeCount = queue_size(&q);

    while(nodeCount > 0)
    {
      BstNode *node = (BstNode *) queue_peek(&q);
      (*printNode)(node->data);
      queue_remove(&q);

      if(node->left != NULL)
      {
        queue_add(&q, node->left);
      }
      if(node->right != NULL)
      {
        queue_add(&q, node->right);
      }
      nodeCount--;
    }
    printf("\n");
  }
}

//Find min value of node in the tree
