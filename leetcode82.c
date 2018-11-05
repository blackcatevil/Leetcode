#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head)
{
  int flag = 0;
  struct ListNode *prev = NULL;
  struct ListNode *cur;
  struct ListNode *front = head;

  if (head == NULL || head->next == NULL)
    return head;

  cur = head;
  while (cur->next != NULL) {
    if (((cur->val)^(cur->next->val)) == 0) {
      flag = 1;
    } else {
      if (!flag) {
	prev = cur;
      } else {
        if (prev != NULL) {
	  prev->next = cur->next;
        } else {
	  front = cur->next;
        }
      }
      flag = 0;
    }
    cur = cur->next;
  }

  if (flag) {
    if (prev != NULL) {
      prev->next = cur->next;
    } else {
      front = cur->next;
    }
  }

  return front;
}

int main()
{
  return 0;
}
