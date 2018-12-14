#include <stdlib.h>
#include <stdio.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
  struct TreeNode* right;
  struct TreeNode* left;

  if (root == NULL)
    return NULL;

  if (root == p)
    return p;
  if (root == q)
    return q;

  left = lowestCommonAncestor(root->left, p, q);
  right = lowestCommonAncestor(root->right, p, q);

  if (left != NULL && right != NULL)
    return root;
  else if (left != NULL)
    return left;
  else if (right != NULL)
    return right;
  else
    return NULL;
}

int main()
{
  return 0;
}
