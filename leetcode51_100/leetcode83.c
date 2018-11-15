#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head)
{
  struct ListNode *cur;
  struct ListNode *prev;

  if (head == NULL || head->next == NULL)
    return head;

  prev = head;
  cur = head->next;
  while (cur != NULL) {
    if (((prev->val)^(cur->val)) == 0) {
      cur = cur->next;
      prev->next = cur;
    } else {
      prev = cur;
      cur = cur->next;
    }
  }

  return head;
}

int main()
{
  return 0;
}
