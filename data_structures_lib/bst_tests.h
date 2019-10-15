#include "include/bst.h"
#include "include/common.h"

void run_bst_tests(void)
{
  int keys[] = {0,1,2,3,4,5,6,7,8,9,10};
  int data[] = {0,1,2,3,4,5,6,7,8,9,10};

  BstNode *root = create_node(&keys[0], &data[0]);
  BstNode *projDir = create_node(&keys[1],&data[1]);
  BstNode *subDir1 = create_node(&keys[2],&data[2]);
  BstNode *subDir2 = create_node(&keys[3],&data[3]);

  root->left = projDir;
  projDir->left = subDir1;
  projDir->right = subDir2;

  Bstree *bst = (Bstree*)malloc(sizeof(Bstree));
  bst->root = root;

  bstree_print(bst, printIntNode);

}
