#include <stdlib.h>
#include <stdio.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
  struct ListNode *p = NULL;
  struct ListNode *head = NULL;

  if (l1 == NULL)
    return l2;
  if (l2 == NULL)
    return l1;

  do {
    if (l1->val > l2->val) {
      if (p != NULL)
	p->next = l2;
      else
	head = l2;

      p = l2;
      l2 = l2->next;
    } else {
      if (p != NULL)
	p->next = l1;
      else
	head = l1;

      p = l1;
      l1 = l1->next;
    }
  } while (l1 != NULL && l2 != NULL);

  if (l1 == NULL)
    p->next = l2;
  else
    p->next = l1;

  return head;
}

int main()
{
  return 0;
}
