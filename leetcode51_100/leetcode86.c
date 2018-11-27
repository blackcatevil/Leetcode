#include <stdlib.h>
#include <stdio.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* partition(struct ListNode* head, int x)
{
  struct ListNode* less = NULL;		// The list contained nodes less than x
  struct ListNode* greater = NULL;	// The list contained nodes greater than or equal to x
  struct ListNode* p = head;
  struct ListNode* tmp = NULL;		// The first node of list greater

  if (head == NULL)
    return NULL;

  while (p != NULL) {
    if (p->val < x) {
      if (less == NULL)
	head = p;
      else
	less->next = p;
      less = p;
    } else {
      if (greater == NULL)
	tmp = p;
      else
	greater->next = p;
      greater = p;
    }
    p = p->next;
  }

  if (less != NULL)
    less->next = tmp;
  if (greater != NULL)
    greater->next = NULL;

  return head;
}

int main()
{
  return 0;
}
