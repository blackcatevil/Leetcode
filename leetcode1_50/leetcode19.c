#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

void _removeNthFromEnd(struct ListNode** head, struct ListNode* prev, struct ListNode* cur, int* n)
{
  if (cur == NULL) {
    (*n)--;
    return;
  }

  _removeNthFromEnd(head, cur, cur->next, n);

  if (*n == 0) {
    if (prev == NULL) {
      *head = cur->next;
    } else {
      prev->next = cur->next;
    }
    free(cur);
  }

  (*n)--;
  return;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
  _removeNthFromEnd(&head, NULL, head, &n);

  return head;
}

int main()
{
  return 0;
}
