#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int set[1024];
int size = 0;
int **a;

void merge(int* a, int front, int mid, int end)
{
  int *tmp;
  int size = end-front+1;
  int l = front, r = mid+1;
  
  tmp = malloc(sizeof(int)*size);

  for (int i = 0; i < size; i++) {
    if (r > end) {
    	tmp[i] = a[l++];
    } else if (l > mid) {
        tmp[i] = a[r++];
    } else if (a[l] < a[r]) {
    	tmp[i] = a[l++];
    } else {
        tmp[i] = a[r++];
    }
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
void _combinationSum2(int* candidates, int start, int candidatesSize, int target, int** columnSizes, int* returnSize)
{

  if (target == 0) {
    (*returnSize)++;

    *columnSizes = (int*)realloc(*columnSizes, sizeof(int)*(*returnSize));
    (*columnSizes)[(*returnSize)-1] = size;

    a = (int**)realloc(a, sizeof(int*)*(*returnSize));
    a[(*returnSize)-1] = malloc(sizeof(int)*size);
    memcpy(a[(*returnSize)-1], set, sizeof(int)*size);

    size--;
    return;
  }

  for (int i = start; i < candidatesSize; i++) {
    if (i != start && candidates[i] == candidates[i-1])
      continue;
    if (candidates[i] <= target) {
      set[size++] = candidates[i];
      _combinationSum2(candidates, i+1, candidatesSize, target-candidates[i], columnSizes, returnSize);
    }
  }
  size--;
}
int** combinationSum2(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize)
{
  *returnSize = 0;

  if (candidatesSize == 0)
    return NULL;

  mergesort(candidates, 0, candidatesSize-1);

  size = 0;
  a = malloc(sizeof(int*));
  *columnSizes = malloc(sizeof(int));

  _combinationSum2(candidates, 0, candidatesSize, target, columnSizes, returnSize);

  if (*returnSize == 0) {
    free(a);
    a = NULL;
  }

  return a;
}
int main()
{
  int candidates[] = {10,1,2,7,6,1,5};
  int target = 8;
  int candidatesSize = sizeof(candidates)/sizeof(int);
  int **ans;
  int *columnSizes;
  int returnSize = 0;

  ans = combinationSum2(candidates, candidatesSize, target, &columnSizes, &returnSize);

  printf("[");
  for (int i = 0; i < returnSize; i++) {
    printf("\n  [ ");
    for (int j = 0; j < columnSizes[i]; j++)
      printf("%d ", ans[i][j]);
    printf("]");
    free(ans[i]);
  }
  printf("\n]\n");
  free(ans);
  free(columnSizes);

  return 0;
}
