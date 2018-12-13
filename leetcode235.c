#include <stdlib.h>
#include <stdio.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
  struct TreeNode** stack;
  struct TreeNode* tmp;
  int size;

  if (root == NULL)
    return NULL;

  tmp = root;
  stack = malloc(sizeof(struct TreeNode*));
  size = 0;
  while (tmp != p) {
    if (tmp == q) {
      free(stack);
      return q;
    }

    stack = (struct TreeNode**)realloc(stack, sizeof(struct TreeNode*)*(size+1));
    stack[size++] = tmp;
    if (p->val > tmp->val)
      tmp = tmp->right;
    else
      tmp = tmp->left;
  }
  stack = (struct TreeNode**)realloc(stack, sizeof(struct TreeNode*)*(size+1));
  stack[size++] = tmp;

  tmp = root;
  for (int i = 0; i < size; i++) {
    if (stack[i] != tmp) {
      tmp = stack[i-1];
      free(stack);
      return tmp;
    }

    if (q->val > tmp->val)
      tmp = tmp->right;
    else
      tmp = tmp->left;
  }

  return p;
}

int main()
{
  return 0;
}
