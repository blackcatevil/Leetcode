#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
  struct TreeNode* stack[1024];
  int *ans;
  int ans_size = 0, top = 0;

  if (root == NULL) {
    *returnSize = 0;
    return NULL;
  }

  ans = malloc(sizeof(int));

  while (root != NULL || top > 0) {
    if (root != NULL) {
      stack[top++] = root;
      root = root->left;
    } else {
      ans = (int*)realloc(ans, sizeof(int)*(++ans_size));
      ans[ans_size-1] = stack[top-1]->val;
      root = stack[top-1]->right;
      top--;
    }
  }

  *returnSize = ans_size;
  return ans;
}

int main()
{
  return 0;
}
