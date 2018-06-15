#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
 
bool isPalindrome(struct ListNode* head) {
    int size = 1;
    int i, j;
    struct ListNode *p = head;
    
    if (head == NULL)
        return true;
    if (head->next == NULL)
        return true;

    while (p->next != NULL) {
        p = p->next;
        size++;
    }

    int *tmp = malloc(sizeof(int)*size);
    p = head;
    for (i = 0; i < size; i++) {
        tmp[i] = p->val;
        p = p->next;
    }

    i = 0;
    j = size-1;
    while (i < j) {
        if (tmp[i] != tmp[j]) {
	    free(tmp);
            return false;
	}
        i++;
        j--;
    }

    free(tmp);
    return true;
}

int main()
{
  printf("%s\n", isPalindrome(NULL)? "True": "False");
  return 0;
}
