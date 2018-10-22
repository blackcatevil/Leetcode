#include <stdlib.h>
#include <stdio.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head)
{
  struct ListNode *p1 = head;
  struct ListNode *p2;
  struct ListNode *front = head;
  struct ListNode *prev = NULL;

  while (p1 != NULL) {
    p2 = p1->next;
    if (p2 == NULL)
      break;
    //swapping
    p1->next = p2->next;
    p2->next = p1;
    if (prev != NULL)
      prev->next = p2;
    if (p1 == head)
      front = p2;
    prev = p1;
    p1 = p1->next;
  }

  return front; 
}

int main(int argc, char **argv)
{
  struct ListNode *head = NULL, *cur;

  for (int i = 1; i < argc; i++) {
    struct ListNode *p = malloc(sizeof(struct ListNode));
    p->val = atoi(argv[i]);
    p->next = NULL;
    if (head == NULL) {
      head = p;
      cur = p;
    } else {
      cur->next = p;
      cur = p;
    }
  }

  head = swapPairs(head);

  while (head != NULL) {
    printf("%d->", head->val);
    head = head->next;
  }
  printf("NULL\n");

  return 0;
}
