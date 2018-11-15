#include <stdlib.h>
#include <stdio.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int sizeA = 0, sizeB = 0;
    int diff;
    struct ListNode *a = headA, *b = headB;
    struct ListNode *target = NULL;

    while (a != NULL || b != NULL) {
        if (a != NULL) {
            a = a->next;
            sizeA++;
        }
        if (b != NULL) {
            b = b->next;
            sizeB++;
        }
    }

    a = headA;
    b = headB;
    diff = abs(sizeA-sizeB);
    if (sizeA > sizeB) {
        while (diff-- > 0)
            a = a->next;
    } else {
        while (diff-- > 0)
            b = b->next;
    }

    while (a != NULL && b != NULL) {
        if (a == b) {
            target = a;
            break;
        }
        a = a->next;
        b = b->next;
    }

    return target;
}

int main()
{
  return 0;
}
