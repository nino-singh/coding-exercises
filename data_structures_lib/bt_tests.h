#include "include/common.h"
#include "include/bt.h"


void run_bt_tests(void)
{
  int data[] = {0,1,2,3,4,5};

  BtNode *root = btree_create_node(&data[1]);
  root->left = btree_create_node(&data[2]);
  root->right = btree_create_node(&data[3]);
  root->left->left = btree_create_node(&data[4]);
  root->left->right = btree_create_node(&data[5]);

  printf("Binary Tree ---- preorder traversal\n");
  btree_preorder_print(root, printIntNode);
  printf("\n");
  printf("Binary Tree ---- inorder traversal\n");
  btree_inorder_print(root, printIntNode);
  printf("\n");
  printf("Binary Tree ---- postorder traversal\n");
  btree_postorder_print(root, printIntNode);
  printf("\n");
}
