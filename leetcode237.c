#include <stdlib.h>
#include <stdio.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

void deleteNode(struct ListNode* node)
{
  struct ListNode *p = node;
  struct ListNode *prev = NULL;

  while (p->next != NULL) {
    p->val = p->next->val;
    prev = p;
    p = p->next;
  }
  prev->next = NULL;
  free(p);
}

int main()
{
  return 0;
}
