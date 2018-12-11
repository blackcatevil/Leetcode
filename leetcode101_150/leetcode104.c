#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int maxDepth(struct TreeNode* root)
{
  int left_depth = 1;
  int right_depth = 1;

  if (root == NULL)
    return 0;

  if (root->left != NULL)
    left_depth += maxDepth(root->left);
  if (root->right != NULL)
    right_depth += maxDepth(root->right);

  return left_depth > right_depth? left_depth: right_depth;
}

int main()
{
  return 0;
}
