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
//Traverse the tree in level order and insert node at first node
//whose left or right child is NULL
void btree_insert(BtNode *root, void *data)
{
  if(root == NULL)
  {
    return;
  }
  Queue *q = queue_create(sizeof(BtNode*));
  queue_add(q, root);

  while(queue_size(q) > 0)
  {
    BtNode *temp = (BtNode*)queue_peek(q);

    if(temp->left == NULL) {
      BtNode *b = btree_create_node(data);
      temp->left = b;
      break;
    }
    else {
      queue_add(q,temp->left);
    }

    if(temp->right == NULL) {
      BtNode *b = btree_create_node(data);
      temp->right = b;
      break;
    }
    else {
      queue_add(q,temp->right);
    }
    queue_remove(q);
  }
}

//Remove node with given key
void btree_remove(BtNode *root, void *data)
{

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

   Queue *q = queue_create(sizeof(BtNode*));
   queue_add(q, root);

   while(queue_size(q) > 0)
  // while(temp)
   {
     BtNode *temp = ((BtNode*)queue_peek(q));
     (*printNode)(temp->data);

     if(temp->left != NULL) {
         queue_add(q, temp->left);
     }

    if(temp->right != NULL) {
      queue_add(q, temp->right);
    }

    queue_remove(q);

   }

}
