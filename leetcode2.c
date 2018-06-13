#include <stdlib.h>
#include <stdio.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
  int carry = 0;
  int d;
  static struct ListNode* head;
  struct ListNode *tmp;
  head = l1;

  do {
    d = l1->val + l2->val + carry;
    carry = d/10;
    l1->val = d%10;

    if (l1->next == NULL) {
      tmp = l2->next;
      while (carry) {
	if (l2->next == NULL) {
	  l2->next = malloc(sizeof(struct ListNode));
	  l2->next->val = 0;
	  l2->next->next = NULL;
	  if (tmp == NULL)
	    tmp = l2->next;
	}
	d = l2->next->val + carry;
	carry = d/10;
	l2->next->val = d%10;
	l2 = l2->next;
      }
      l1->next = tmp;
      break;
    }
    if (l2->next == NULL) {
      while (carry) {
	if (l1->next == NULL) {
	  l1->next = malloc(sizeof(struct ListNode));
	  l1->next->val = 0;
	  l1->next->next = NULL;
	}
	d = l1->next->val + carry;
	carry = d/10;
	l1->next->val = d%10;
	l1 = l1->next;
      }
      break;
    }

    l1 = l1->next;
    l2 = l2->next;
  } while(l1 != NULL && l2 != NULL);

  return head;
}

void print_list(struct ListNode* head)
{
  struct ListNode *list = head;
  while (list != NULL) {
    printf("%d", list->val);
    list = list->next;
  }
  return;
}

int main()
{
  int a[2] = {2, 4};
  int b[2] = {8, 5};
  struct ListNode *l1 = NULL;
  struct ListNode *l2 = NULL;
  struct ListNode *cur = NULL;

  for (int i = 0; i < sizeof(a)/sizeof(int); i++) {
    struct ListNode *tmp = malloc(sizeof(struct ListNode));
    tmp->val = a[i];
    tmp->next = NULL;
    if (cur != NULL) {
      cur->next = tmp;
    }
    else {
      l1 = tmp;
    }
    cur = tmp;
  }

  cur = NULL;
  for (int i = 0; i < sizeof(b)/sizeof(int); i++) {
    struct ListNode *tmp = malloc(sizeof(struct ListNode));
    tmp->val = b[i];
    tmp->next = NULL;
    if (cur != NULL) {
      cur->next = tmp;
    }
    else {
      l2 = tmp;
    }
    cur = tmp;
  }

  print_list(l1);
  printf("+");
  print_list(l2);
  printf("=");
  print_list(addTwoNumbers(l1, l2));
  printf("\n");

  return 0;
}
