#include "../include/bt.h"
#include "../include/queue.h"

//Create a new bst node
BtNode *btree_create_node(void*data)
{
  BtNode *node = (BtNode*)malloc(sizeof(BtNode));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

//Insert a new node in the binary search tree
void btree_insert(BtNode *root, void *key, void *data)
{

}

//Remove node with given key
void btree_remove(BtNode *root, void *key)
{

}

//Find node with given key an return data
void *btree_retrieve(BtNode *root, void *key)
{

}

//Check if node exists with given key
bool btree_contains(BtNode *root, void *key)
{

}

//Return number of nodes in tree
int btree_size(BtNode *root)
{

}

//Return true if tree is empty
bool btree_isEmpty(BtNode *root)
{
  return false;
}

//Traverse (Root, left, right)
void btree_preorder_print(BtNode *node, void (*printNode)(void *))
{
  if(node == NULL)
  {
    return;
  }
  printNode(node->data);
  btree_preorder_print(node->left, printNode);
  btree_preorder_print(node->right,printNode);
}

//Traverse (Left, right, Root)
void btree_postorder_print(BtNode *node, void (*printNode)(void *))
{
  if(node == NULL)
  {
    return;
  }
  btree_postorder_print(node->left, printNode);
  btree_postorder_print(node->right, printNode);
  printNode(node->data);
}

//Traverse (Left, Root, Right)
void btree_inorder_print(BtNode *node, void (*printNode)(void *))
{
  if(node == NULL){
    return;
  }
  btree_inorder_print(node->left, printNode);
  printNode(node->data);
  btree_inorder_print(node->right, printNode);
}

//Traverse each level left to right
void btree_levelorder_print(BtNode *root, void (*printNode)(void *))
{
  if(root == NULL)
  {
    return;
  }

   Queue *q = queue_create(sizeof(int));

   queue_add(q, root);

   while(queue_size() > 0)
   {
     BtNode *node = (BtNode*)queue_peek();
     (*printNode)(node->data);
     queue_remove();

     if(node->left != NULL) {
         queue.add(node->left);
     }

    if(node->right != NULL) {
      queue.add(node->right);
    }
   }

}
