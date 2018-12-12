#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int minDepth(struct TreeNode* root)
{
  int left_depth = 1;
  int right_depth = 1;

  if (root == NULL)
    return 0;

  if (root->left == NULL)
    return minDepth(root->right)+1;
  if (root->right == NULL)
    return minDepth(root->left)+1;

  left_depth += minDepth(root->left);
  right_depth += minDepth(root->right);

  return left_depth < right_depth? left_depth: right_depth;
}

int main()
{
  return 0;
}
