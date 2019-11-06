#include "include/bst.h"
#include "include/common.h"

#define TREE_SIZE 10

void run_bst_tests(void)
{

  int keys[TREE_SIZE] = {2,4,6,8,10,12,14,16,18,20};
  char* data[TREE_SIZE] = {"hello", "world", "my", "name", "is", "nano", "singh", "i", "like","this"};

  //Construct an empty tree
  Bstree *tree = create_empty_tree(compareInts);

  //Insert node into tree
  bstree_insert(tree, &keys[5], data[0]);
  bstree_insert(tree, &keys[2], data[1]);
  bstree_insert(tree, &keys[3], data[2]);
  bstree_insert(tree, &keys[8], data[3]);
  // bstree_insert(tree, &keys[6], data[4]);

  //Print the binary search Tree
  printf("---- Binary Search Tree ----\n");
  bstree_print(tree, printKeyValueStringNode);

}
