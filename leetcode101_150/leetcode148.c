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

  p->next = l1 == NULL? l2 :l1;

  return head;
}

struct ListNode* _sortList(struct ListNode* head, int size)
{
  struct ListNode *l1 = head;
  struct ListNode *l2 = head;
  struct ListNode *tmp;

  if (size == 1)
    return head;

  for (int i = 0; i < size/2; i++) {
    tmp = l2;
    l2 = l2->next;
  }
  tmp->next = NULL;

  l1 = _sortList(l1, size/2);
  l2 = _sortList(l2, size - size/2);

  return mergeTwoLists(l1, l2);
}

struct ListNode* sortList(struct ListNode* head)
{
  int size = 0;
  struct ListNode *p = head;

  while (p != NULL) {
    size++;
    p = p->next;
  }

  return head == NULL? NULL: _sortList(head, size);
}

int main()
{
  return 0;
}
