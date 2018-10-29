#include <stdlib.h>
#include <stdio.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k)
{
  struct ListNode *tier = head;
  struct ListNode *p = head;
  int len = 1;

  if (head == NULL)
    return NULL;
  if (k == 0)
    return head;

  while (tier->next != NULL) {
    len++;
    tier = tier->next;
  }

  if (len == 1)
    return head;

  k %= len;
  if (k != 0)
    k = len-k;

  if (k > 0) {
    for (int i = 1; i < k; i++)
      p = p->next;
    tier->next = head;
    head = p->next;
    p->next = NULL;
  }

  return head;
}

int main()
{
  return 0;
}
