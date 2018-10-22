#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Size;
int *Nums;
int **ans;

void _swap(int* a, int* b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void _permute(int* nums, int numsSize, int* returnSize)
{
  if (numsSize == 1) {
    (*returnSize)++;
    ans = (int**)realloc(ans, sizeof(int*)*(*returnSize));
    ans[(*returnSize)-1] = malloc(sizeof(int)*Size);
    memcpy(ans[(*returnSize)-1], Nums, sizeof(int)*Size);
    return;
  }
  for (int i = 0; i < numsSize; i++) {
    _swap(nums, nums+i);
    _permute(nums+1, numsSize-1, returnSize);
    _swap(nums, nums+i);
  }
}
int** permute(int* nums, int numsSize, int* returnSize)
{
  Size = numsSize;
  Nums = nums;
  ans = malloc(sizeof(int*));
  *returnSize = 0;

  _permute(nums, numsSize, returnSize);

  if (*returnSize == 0) {
    free(ans);
    ans = NULL;
  }

  return ans;
}
int main()
{
  int nums[] = {1,2,3,4};
  int numsSize = sizeof(nums)/sizeof(int);
  int size;
  int **ans;

  ans = permute(nums, numsSize, &size);

  printf("[");
  for (int i = 0; i < size; i++) {
    printf("\n  [");
    for (int j = 0; j < numsSize; j++)
      printf("%d ", ans[i][j]);
    free(ans[i]);
    printf("]");
  }
  printf("\n]\n");
  free(ans);

  return 0;
}
