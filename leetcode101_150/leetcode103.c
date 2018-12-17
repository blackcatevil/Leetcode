#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int** zigzagLevelOrder(struct TreeNode* root, int** columnSizes, int* returnSize)
{
  struct TreeNode*** nodes;
  int** ans;
  int* colsize;
  int size = 0;

  *returnSize = 0;
  *columnSizes = NULL;

  if (root == NULL)
    return NULL;

  // Init with root node
  nodes = malloc(sizeof(struct TreeNode**));
  size++;
  nodes[0] = malloc(sizeof(struct TreeNode*));
  nodes[0][0] = root;
  colsize = malloc(sizeof(int));
  colsize[0] = 1;

  // For each level node, append their children to list, and go on
  for (int i = 0; i < size; i++) {
    int top = 0;
    nodes = (struct TreeNode***)realloc(nodes, sizeof(struct TreeNode**)*(size+1));
    nodes[size] = malloc(sizeof(struct TreeNode*));
    for (int j = 0; j < colsize[i]; j++) {
      struct TreeNode* p = nodes[i][j];
      if (p->left != NULL) {
	nodes[size] = (struct TreeNode**)realloc(nodes[size], sizeof(struct TreeNode*)*(top+1));
	nodes[size][top++] = p->left;
      }
      if (p->right != NULL) {
	nodes[size] = (struct TreeNode**)realloc(nodes[size], sizeof(struct TreeNode*)*(top+1));
	nodes[size][top++] = p->right;
      }
    }
    // Is there any child node?
    if (top == 0) {
      // No, delete the new array
      free(nodes[size]);
      nodes = (struct TreeNode***)realloc(nodes, sizeof(struct TreeNode**)*size);
    } else {
      // Yes, updates the size to keep looping
      size++;
      colsize = (int*)realloc(colsize, sizeof(int)*size);
      colsize[size-1] = top;
    }
  }

  ans = malloc(sizeof(int*)*size);
  for (int i = 0; i < size; i++) {
    ans[i] = malloc(sizeof(int)*colsize[i]);
    for (int j = 0; j < colsize[i]; j++) {
      if (i%2 == 1)
        ans[i][colsize[i]-1-j] = nodes[i][j]->val;
      else
        ans[i][j] = nodes[i][j]->val;
    }
    free(nodes[i]);
  }
  free(nodes);
  
  *returnSize = size;
  *columnSizes = colsize;

  return ans;
}

int main()
{
  return 0;
}
