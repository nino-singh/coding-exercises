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
  ll_prepend(&head, 4);
  ll_print(head);
  ll_append(&head, 5);
  ll_print(head);
  ll_insert(&n2, 66);
  ll_print(head);

  return 0;
}