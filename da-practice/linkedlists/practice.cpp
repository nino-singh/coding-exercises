#include "linkedList_Single.h"
#include <iostream>
using namespace std;

int main()
{
  cout << "Creating singly linked list\n";

  struct Node *head = NULL;
  struct Node *n1 = NULL;
  struct Node *n2 = NULL;
  struct Node *n3 = NULL;

  head = (struct Node*)malloc(sizeof(struct Node));
  n1 = (struct Node*)malloc(sizeof(struct Node));
  n2 = (struct Node*)malloc(sizeof(struct Node));
  n3 = (struct Node*)malloc(sizeof(struct Node));

  head->next = n1;
  head->data = 0;
  n1->next = n2;
  n1->data = 1;
  n2->next = n3;
  n2->data = 2;
  n3->next = NULL;
  n3->data = 3;


  ll_print(head);
  printf("--- Prepend ---\n");
  ll_prepend(&head, 4);
  ll_print(head);

  printf("--- Append ---\n");
  ll_append(&head, 5);
  ll_append(&head, 6);
  ll_append(&head, 7);
  ll_append(&head, 8);
  ll_print(head);

  printf("---- Insert ---\n");
  ll_insert(&n2, 66);
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
  head->next->next->next->next = head;
  printf("--- Detect loop ---");
  if(ll_isLoopPresent(&head))
  {
    printf("Loop detected!\n");
  }
  else {
    printf("No loop\n");
  }


  return 0;
}
