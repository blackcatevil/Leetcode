#include <stdlib.h>
#include <stdio.h>

 struct ListNode {
   int val;
   struct ListNode *next;
 };

struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode *tmp;
    struct ListNode *p1 = NULL;
    struct ListNode *p2 = head;
    
    while (p2 != NULL) {
            tmp = p1;
            p1 = p2;
            p2 = p2->next;
            p1->next = tmp;
        }

    return p1;
}

int main()
{
  return 0;
}
