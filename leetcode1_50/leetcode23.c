#include <stdlib.h>
#include <stdio.h>

struct ListNode {
  int val;
  struct ListNode *next;
};
struct ListNode* insertionSortList(struct ListNode* head)
{
  struct ListNode *p1, *p2, *tmp, *current, *tier, *front;

  if (head == NULL)
    return NULL;

  current = head->next;
  tier = head;
  front = head;
  while (current != NULL) {
      p1 = NULL;
      p2 = front;
      while (p2 != current) {
            if (p2->val > current->val) {
	           tmp = current->next;
	    
	           if (p1 != NULL)
	             p1->next = current;
	           else
	             front = current;
	           current->next = p2;
	           tier->next = tmp;
	           current = tmp;
	           break;
	          }
            else {
	           p1 = p2;
	           p2 = p2->next;
	          }
          }
      if (p2 == current) {
            tier = current;
            current = current->next;
          }
    }

  return front;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode *ans = NULL;
    struct ListNode *cur, *prev = NULL;
    int i;

    if (listsSize == 0)
        return NULL;
    if (listsSize == 1)
        return lists[0];

    for (i = 0; i < listsSize; i++) {
            cur = lists[i];
            if (cur != NULL) {
	                if (ans == NULL)
	                    ans = cur;
	                if (prev == NULL) {
			                prev = cur;
			                continue;
			            }
	                while (prev->next != NULL)
	                    prev = prev->next;
	                prev->next = cur;
	                prev = cur;
	            }
        }
    ans = insertionSortList(ans);

    return ans;
}

int main(int argc, char **argv)
{
  return 0;
}
