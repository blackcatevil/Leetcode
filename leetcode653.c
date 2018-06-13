#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
};
bool findkey(struct TreeNode* node, int key)
{
    if (node == NULL)
        return false;
    if (node->val == key)
        return true;
    if (node->val < key)
        return findkey(node->right, key);
    else
        return findkey(node->left, key);
}
bool findTarget(struct TreeNode* root, int k)
{
    struct TreeNode* tmp;
    int key;
    int smallest;
    int largest;

    if (root == NULL)
        return false;

    tmp = root;
    while (tmp->left != NULL)
        tmp = tmp->left;
    smallest = tmp->val;

    tmp = root;
    while (tmp->right != NULL)
        tmp = tmp->right;
    largest = tmp->val;

    for (int i = smallest; i <= largest; i++) {
            key = k-i;
            if (key != i && findkey(root, key) && findkey(root, i))
                return true;
        }
    return false;
}

int main()
{
  return 0;
}
