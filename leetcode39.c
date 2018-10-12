#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int set[1024];
int size = 0;
int **a;

void _combinationSum(int* candidates, int start, int candidatesSize, int target, int** columnSizes, int* returnSize)
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
    if (candidates[i] <= target) {
      set[size++] = candidates[i];
      _combinationSum(candidates, i, candidatesSize, target-candidates[i], columnSizes, returnSize);
    }
  }
  size--;
}
int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize)
{
  *returnSize = 0;

  if (candidatesSize == 0)
    return NULL;

  size = 0;
  a = malloc(sizeof(int*));
  *columnSizes = malloc(sizeof(int));

  _combinationSum(candidates, 0, candidatesSize, target, columnSizes, returnSize);

  if (*returnSize == 0) {
    free(a);
    a = NULL;
  }

  return a;
}
int main()
{
  int candidates[] = {1,2,3,5};
  int target = 10;
  int candidatesSize = sizeof(candidates)/sizeof(int);
  int **ans;
  int *columnSizes;
  int returnSize = 0;

  ans = combinationSum(candidates, candidatesSize, target, &columnSizes, &returnSize);

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
