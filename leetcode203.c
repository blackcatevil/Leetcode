#include <stdlib.h>
#include <stdio.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val)
{
  struct ListNode *p = head;
  struct ListNode *prev = NULL;
  struct ListNode *tmp;

  while (p != NULL) {
    if (p->val == val) {
      tmp = p;
      if (p == head) {
	p = p->next;
	head = p;
      } else {
	prev->next = p->next;
	p = p->next;
      }
      free(tmp);
    } else {
      prev = p;
      p = p->next;
    }
  }

  return head;
}

int main()
{
  return 0;
}
