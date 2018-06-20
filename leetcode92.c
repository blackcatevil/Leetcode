#include <stdlib.h>
#include <stdio.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* reverseBetween(struct ListNode* head, int m, int n)
{
    struct ListNode *front, *tier, *p1;
    struct ListNode *current = head, *tmp = NULL;

    for (int i = 1; i <= n; i++) {
            if (i == m) {
	                front = tmp;
	                tier = current;
	                p1 = front;
	            }
            if (i >= m) {
	                tmp = p1;
	                p1 = current;
	                current = current->next;
	                p1->next = tmp;
	                continue;
	            }
            tmp = current;
            current = current->next;
        }
    
    if (front != NULL)
        front->next = p1;
    tier->next = current;
    
    return m > 1? head: p1;
}

int main()
{
  return 0;
}
