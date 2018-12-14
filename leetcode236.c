#include <stdlib.h>
#include <stdio.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int findNode(struct TreeNode* root, struct TreeNode* target, struct TreeNode*** stack, int* size)
{
  if (root == NULL)
    return 0;

  (*stack) = (struct TreeNode**)realloc(*stack, sizeof(struct TreeNode*)*((*size)+1));
  (*stack)[(*size)++] = root;
  if (root == target ||
      findNode(root->left, target, stack, size) > 0 ||
      findNode(root->right, target, stack, size) > 0)
    return 1;

  (*stack) = (struct TreeNode**)realloc(*stack, sizeof(struct TreeNode*)*((*size)-1));
  (*size)--;
  return 0;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
  struct TreeNode** pstack = malloc(sizeof(struct TreeNode*));
  struct TreeNode** qstack = malloc(sizeof(struct TreeNode*));
  struct TreeNode* ans;
  int psize = 0;
  int qsize = 0;

  if (root == NULL)
    return NULL;

  findNode(root, p, &pstack, &psize);
  findNode(root, q, &qstack, &qsize);
  if (psize > qsize)
    psize = qsize;

  for (int i = 1; i < psize; i++) {
    if (pstack[i] != qstack[i]) {
      ans = pstack[i-1];
      break;
    }
    ans = pstack[i];
  }
  free(pstack);
  free(qstack);

  return ans;
}

int main()
{
  return 0;
}
