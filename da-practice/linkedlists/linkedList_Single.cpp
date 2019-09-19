#include "linkedList_Single.h"

/* print nodes of linked list */
void ll_print(struct Node *n)
{
  printf("---- Linked List ----\n");
  while(n != NULL)
  {
    printf("LL node: %d\n", n->data);
    n = n->next;
  }
}

/* Add node after given node */
void ll_insert(struct Node **node_ref, int newData)
{
  struct Node *afterNode = *node_ref;
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = newData;
  newNode->next = afterNode->next;
  afterNode->next = newNode;
}

/* Add node to front of list
* Make the head pointer, point to new node which is now n1
*/
void ll_prepend(struct Node **head_ref, int newData)
{
  struct Node *n = (struct Node *)malloc(sizeof(struct Node));

  //Check if list is empty
  if(*head_ref == NULL)
  {
    n->data = newData;
    n->next = NULL;
    *head_ref = n;
  }
  else
  {
    n->data = newData;
    n->next = *head_ref;
    *head_ref = n;
  }
}

/* Add node to end of list */
void ll_append(struct Node **head_ref, int newData)
{
  struct Node *n = (struct Node*)malloc(sizeof(struct Node));

  if(*head_ref == NULL)
  {
    n->data = newData;
    n->next = NULL;
    *head_ref = n;
  }
  else
  {
    struct Node *iter = *head_ref;
    while(iter->next != NULL)
    {
      iter = iter->next;
    }
    n->data = newData;
    n->next = NULL;
    iter->next = n;
  }
}

/* Remove node after given node in list */
void ll_remove(struct Node **head_ref, int key)
{
  struct Node *curr = *head_ref;
  struct Node *prev = *head_ref;

  if(curr != NULL && curr->data == key)
  {
    *head_ref = curr->next;
    free(curr);
    return;
  }

  while(curr != NULL && curr->data != key)
  {
    prev = curr;
    curr=curr->next;
  }

  //Traversed entire list and key wasn't found, return
  if(curr == NULL)
  {
    return;
  }
  prev->next = curr->next;
  free(curr);

}

/* Remove node at given position in list */
void ll_removeAt(struct Node **head_ref, int pos)
{
  struct Node *curr = *head_ref;
  struct Node *prev = *head_ref;

  if(pos == 0)
  {
      *head_ref = curr->next;
      free(curr);
      return;
  }
  for(int i = 0; i < pos; i++)
  {
    prev = curr;
    curr = curr->next;
  }

  if(curr == NULL)
  {
    return;
  }

  prev->next = curr->next;
  free(curr);

}

/* Get number of nodes in the list */
int ll_length(struct Node **head_ref)
{
  int len = 0;
  struct Node *iter = *head_ref;

  while(iter != NULL)
  {
    len++;
    iter = iter->next;
  }
  return len;
}

/* Get Nth node from end of list */
int ll_getNthFromEnd(struct Node **head_ref, int n)
{
  int len = ll_length(head_ref);

  if(n > len)
  {
    return -1;
  }


  int pos = len - n;
  struct Node *iter = *head_ref;

  for(int i = 0; iter != NULL && i < pos; i++)
  {
    iter= iter->next;
  }

  return iter-> data;
}

/* Get node in middle of the list */
int ll_getMiddle_v1(struct Node **head_ref)
{
  int len = ll_length(head_ref);
  int middle = (len/2) + 1;
  return ll_getNthFromEnd(head_ref, middle);
}

/* Get node in middle of the list, using fast and slow pointer */
int ll_getMiddle_v2(struct Node **head_ref)
{
  struct Node *slow = *head_ref;
  struct Node *fast = *head_ref;

  while(fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow->data;
}

/* Get node in middle of the list */
int ll_getFreqofNode(struct Node **head_ref, int key)
{
  struct Node *iter = *head_ref;
  int cnt = 0;

  while(iter != NULL)
  {
    if(iter->data == key)
    {
      cnt++;
    }
    iter=iter->next;
  }

  return cnt;
}

/* Detect if loop is present in the linked list */
unsigned int ll_isLoopPresent(struct Node **head_ref)
{
  struct Node *fast = *head_ref;
  struct Node *slow = *head_ref;
  struct Node *loopBegin = NULL;
//  unsigned int isLoop = 0;
  unsigned int loopLen = 0;

  while(slow != NULL && fast != NULL && fast->next != NULL)
  {

    fast = fast->next->next;
    slow = slow->next;

    if(slow == fast)
    {
      loopBegin = slow;
      slow=slow->next;
      loopLen++;

      while(loopBegin != slow)
      {
        loopLen++;
        slow=slow->next;
      }

      return loopLen;
    }
  }

  return loopLen;
}

/* Reverse the nodes of the linked list */
void ll_reverse(struct Node **head_ref)
{
  //Initialize three pointers
  struct Node *prev = NULL;
  struct Node *curr = *head_ref;
  struct Node *next = NULL;

  /*Always keep track of head which points to prev since this is now three
  first node in the list*/

  /* Make sure to save current's next before you make curr next equal to prev
  You're basically iterating through and reversing each link to point in the
  opposite direction */

  while(curr != NULL)
  {
    //Save current's next so we can increment forward
    next = curr->next;

    //Reverse the link so that current's next is now previous
    curr->next = prev;

    //Move pointers one position ahead
    prev = curr;
    curr = next;
  }
  *head_ref = prev;
}

/*Compare contents of two lists for equality */
unsigned int ll_compare(struct Node **list1, struct Node **list2)
{
  struct Node *iter1 = *list1;
  struct Node *iter2 = *list2;
  unsigned int res = 1;

  while(iter1 != NULL && iter2 != NULL)
  {
    if(iter1->data != iter2->data)
    {
      return 0;
    }
    iter1=iter1->next;
    iter2=iter2->next;
  }

  //At this point they must both be null if lists are identical
  return (iter1 == NULL && iter2 == NULL);
}

/* Check if nodes in list are a palindrome */
int ll_isPalindrome(struct Node **head_ref)
{

  //Find middle position
  struct Node *slow = *head_ref;
  struct Node *fast = *head_ref;
  int pos = 1;

  while(fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
    pos++;
  }
  //Save middle node
  struct Node *midNode = slow;

  struct Node *second_half = NULL;
  struct Node *first_half = *head_ref;

  //Check if length of list is odd, and find second half
  //If list is odd, don't include midNode in second half of list
  if((pos*2) % 2)
  {
    second_half = midNode->next;
  }
  else{
    second_half = midNode;
  }

  //Reverse second half
  ll_reverse(&second_half);

  unsigned int isPalindrome = 0;

  //Compare first and second half of list for equality
  isPalindrome = ll_compare(&first_half, &second_half);

  ll_reverse(&second_half);

  return isPalindrome;
}

/*Remove duplicates from list */
void ll_removeDuplicates(struct Node **head_ref)
{
  struct Node *curr = *head_ref;
  struct Node *next = curr->next;
  struct Node *saved = NULL;

  while(next != NULL)
  {
    if(curr->data == next->data)
    {
      //save current's next so we can delete it
      saved = next;
      //Make current's next equal to next next
      curr->next = next->next;
      free(next);

      //Move pointers up one
      curr = curr->next;
      next = curr->next;
    }
    else {
      curr = curr->next;
      next = next->next;
    }
  }
}
