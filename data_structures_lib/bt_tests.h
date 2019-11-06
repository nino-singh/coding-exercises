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

  printf("Binary Tree ---- Level order traversal\n");
  btree_levelorder_print(root, printIntNode);
  printf("\n");

  int data2[] = {10,11,7,9,15,8};

  BtNode* root2 = btree_create_node(&data2[0]);
  root2->left = btree_create_node(&data2[1]);
  root2->left->left = btree_create_node(&data2[2]);
  root2->right = btree_create_node(&data2[3]);
  root2->right->left = btree_create_node(&data2[4]);
  root2->right->right = btree_create_node(&data2[5]);

  printf("Binary Tree ---- Level order traversal\n");
  int newData = 12;
  btree_insert(root2, &newData);
  btree_levelorder_print(root2, printIntNode);
  printf("\n");

}
