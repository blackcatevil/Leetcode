struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int _sumOfLeftLeaves(struct TreeNode* root, bool isleft)
{
    int sum = 0;
    if (root == NULL)
        return 0;
    sum += _sumOfLeftLeaves(root->left, true);
    sum += _sumOfLeftLeaves(root->right, false);
    if (isleft && root->left == NULL && root->right == NULL)
        sum += root->val;
    return sum;
}
int sumOfLeftLeaves(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    return _sumOfLeftLeaves(root->left, true) + _sumOfLeftLeaves(root->right, false);
}

int main()
{
  return 0;
}
