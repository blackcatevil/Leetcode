#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Size;
int *Nums;
int **ans;

void merge(int* a, int front, int mid, int end)
{
  int *tmp;
  int size = end-front+1;
  int l = front, r = mid+1;
  
  tmp = malloc(sizeof(int)*size);

  for (int i = 0; i < size; i++) {
    if (r > end)
    	tmp[i] = a[l++];
    else if (l > mid)
        tmp[i] = a[r++];
    else if (a[l] < a[r])
    	tmp[i] = a[l++];
    else
        tmp[i] = a[r++];
  }

  memcpy(a+front, tmp, sizeof(int)*size);
  free(tmp);
}

void mergesort(int* a, int front, int end)
{
  if (front < end) {
    int mid = (front+end)/2;
    mergesort(a, front, mid);
    mergesort(a, mid+1, end);
    merge(a, front, mid, end);
  }
}

void _swap(int* a, int* b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void _permuteUnique(int* nums, int numsSize, int* returnSize)
{
  if (numsSize == 1) {
    (*returnSize)++;
    ans = (int**)realloc(ans, sizeof(int*)*(*returnSize));
    ans[(*returnSize)-1] = malloc(sizeof(int)*Size);
    memcpy(ans[(*returnSize)-1], Nums, sizeof(int)*Size);
    return;
  }

  for (int i = 0; i < numsSize; i++) {
    if (i != 0 && *(nums+i) == *(nums+i-1))
      continue;

    _swap(nums, nums+i);
    mergesort(nums, 1, numsSize-1);
    _permuteUnique(nums+1, numsSize-1, returnSize);
    mergesort(nums, 0, numsSize-1);
  }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize)
{
  Size = numsSize;
  Nums = nums;
  ans = malloc(sizeof(int*));
  *returnSize = 0;

  mergesort(nums, 0, numsSize-1);
  _permuteUnique(nums, numsSize, returnSize);

  if (*returnSize == 0) {
    free(ans);
    ans = NULL;
  }

  return ans;
}
int main()
{
  int nums[] = {0,1,0,0,9};
  int numsSize = sizeof(nums)/sizeof(int);
  int size;
  int **ans;

  ans = permuteUnique(nums, numsSize, &size);

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
