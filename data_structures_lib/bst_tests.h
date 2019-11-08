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
  bstree_insert(tree, &keys[9], data[9]);
  bstree_insert(tree, &keys[5], data[0]);
  bstree_insert(tree, &keys[2], data[1]);
  bstree_insert(tree, &keys[3], data[2]);
  bstree_insert(tree, &keys[8], data[3]);
  bstree_insert(tree, &keys[7], data[4]);
  bstree_insert(tree, &keys[6], data[5]);

  //Print the binary search Tree
  printf("---- Binary Search Tree ----\n");
  bstree_print(tree, printKeyValueStringNode);

  BstNode *found = bstree_contains(tree, &keys[3]);

  printf("---- Binary Search Tree: Contains ----\n");
  if(found) {
    printf("Tree contains key: %d\n", *((int *)found->key));
  } else {
    printf("Key not found.\n");
  }

    printf("---- Binary Search Tree: Find Min ----\n");
    BstNode *min = bstree_getMin(tree);

    if(min) {
      printf("Min key is : %d\n", *((int*)min->key));
    }

    int a = 50;
    int b = 30;
    int c = 70;
    int d = 20;
    int e = 40;
    int f = 60;
    int g = 80;

    char *str50 = "50";
    char *str30 = "30";
    char *str70 = "70";
    char *str20 = "20";
    char *str40 = "30";
    char *str60 = "60";
    char *str80 = "80";
    //char * Data[TREE_SIZE] = {"50", "30", "20", "40","70", "60", "80"};
    //int Data[TREE_SIZE] = {50, 30, 20, 40, 70, 60, 80};

    Bstree *tree2 = create_empty_tree(compareInts);

    printf("\n---- Binary Search Tree: ----\n");
    bstree_insert(tree2, &a, str50); //50
    bstree_insert(tree2, &b, str30); //30
    bstree_insert(tree2, &c, str70); //70
    bstree_insert(tree2, &d, str20); //20
    bstree_insert(tree2, &e, str40); //40
    bstree_insert(tree2, &f, str60); //60
    bstree_insert(tree2, &g, str80); //80

    bstree_print(tree2, printKeyValueStringNode);

    printf("\n---- Binary Search Tree: delete 20----\n");
    bstree_remove(tree2, &d);
    bstree_print(tree2, printKeyValueStringNode);
}
