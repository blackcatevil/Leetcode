#include <stdlib.h>
#include <stdio.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
  struct TreeNode* current = root;

  if (root == NULL)
    return NULL;

  while (current != NULL) {
    if (p->val == current->val)
      return p;
    if (q->val == current->val)
      return q;
    if ((p->val > current->val && q->val < current->val) ||
	(q->val > current->val && p->val < current->val))
      return current;

    if (p->val > current->val && q->val > current->val)
      current = current->right;
    else
      current = current->left;
  }

  // Input error!!
  return NULL;
}

int main()
{
  return 0;
}
