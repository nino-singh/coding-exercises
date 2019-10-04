#include "linkedList_Single.h"
#include <iostream>
using namespace std;

int main()
{
  cout << "Creating singly linked list\n";

  struct Node *head = NULL;

  printf("--- Append new nodes to list ---\n");
  ll_append(&head, 1);
  ll_append(&head, 2);
  ll_append(&head, 3);
  ll_append(&head, 4);
  ll_append(&head, 5);
  ll_append(&head, 6);

  ll_print(head);

  printf("--- Get middle node ----\n");
  printf("Data is: %d\n", ll_getMiddle_v2(&head));
  ll_print(head);

  printf("--- Prepend ---\n");
  ll_prepend(&head, 50);
  ll_print(head);

  printf("---- Insert ---\n");
  ll_insert(&head->next->next->next, 66);
  ll_print(head);

  printf("--- Delete node at pos 3 ---\n");
  ll_removeAt(&head, 3);
  ll_print(head);

  printf("--- Delete node key 2---\n");
  ll_remove(&head, 2);
  ll_print(head);

  printf("--- Length of list ---\n");
  printf("%d\n", ll_length(&head));

  printf("--- Get 3rd node from end ---\n");
  printf("Data is: %d\n", ll_getNthFromEnd(&head, 3));

  printf("--- Get middle node ----\n");
  printf("Data is: %d\n", ll_getMiddle_v2(&head));
  ll_print(head);

  //Create loop for testing
  head->next->next->next->next->next = head->next->next;
  printf("--- Detect loop ---");
  int loopLen = ll_isLoopPresent(&head);
  if(loopLen)
  {
    printf("Loop detected: %d nodes in length\n", loopLen);
  }
  else {
    printf("No loop\n");
  }

  struct Node *list2 = (struct Node*)malloc(sizeof(struct Node));
  list2 = NULL;

  //Create palidrome with even number of nodes for test
  ll_append(&list2, 60);
  ll_append(&list2, 1);
  ll_append(&list2, 4);
  ll_append(&list2, 1);
  ll_append(&list2, 60);
  ll_print(list2);

  printf("Is palindrome? : %d\n", ll_isPalindrome(&list2));
  ll_print(list2);

  //Create palindrome with odd number of nodes for test
  struct Node *list3 = (struct Node*)malloc(sizeof(struct Node));
  list3 = NULL;

  ll_append(&list3, 10);
  ll_append(&list3, 3);
  ll_append(&list3, 4);
  ll_append(&list3, 1);
  ll_append(&list3, 4);
  ll_append(&list3, 3);
  ll_append(&list3, 10);
  ll_print(list3);

  printf("Is palindrome? : %d\n", ll_isPalindrome(&list3));

  //Create palindrome with odd number of nodes for test
  struct Node *list4 = (struct Node*)malloc(sizeof(struct Node));
  list4 = NULL;

  ll_append(&list4, 1);
  ll_append(&list4, 3);
  ll_append(&list4, 4);
  ll_append(&list4, 4);
  ll_append(&list4, 6);
  ll_append(&list4, 7);
  ll_append(&list4, 10);
  ll_append(&list4, 10);
  ll_append(&list4, 12);
  ll_print(list4);

  printf("Is palindrome? : %d\n", ll_isPalindrome(&list4));

  printf("--- Remove Duplicates ---\n");
  ll_removeDuplicates(&list4);
  ll_print(list4);

  printf("---- Swap nodes 4 and 10 ----\n");
  ll_swapNodes(&list4, 4, 10);
  ll_print(list4);
  
  return 0;
}
