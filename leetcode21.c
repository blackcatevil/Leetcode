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

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p = l1;

    if (p == NULL)
        return insertionSortList(l2);

    while(p->next != NULL)
        p = p->next;
    p->next = l2;

    return insertionSortList(l1);
}
