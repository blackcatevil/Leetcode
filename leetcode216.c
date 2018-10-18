#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int set[1024];
int size = 0;
int **a;

void _combinationSum3(int* candidates, int start, int limit, int target, int** columnSizes, int* returnSize)
{

  if (target == 0) {
    if (size == limit) {

      (*returnSize)++;

      *columnSizes = (int*)realloc(*columnSizes, sizeof(int)*(*returnSize));
      (*columnSizes)[(*returnSize)-1] = size;

      a = (int**)realloc(a, sizeof(int*)*(*returnSize));
      a[(*returnSize)-1] = malloc(sizeof(int)*size);
      memcpy(a[(*returnSize)-1], set, sizeof(int)*size);
    }
    size--;
    return;
  }

  for (int i = start; i < 9; i++) {
    if (candidates[i] <= target) {
      set[size++] = candidates[i];
      if (size == limit && target-candidates[i] != 0) {
	size--;
	continue;
      } else {
        _combinationSum3(candidates, i+1, limit, target-candidates[i], columnSizes, returnSize);
      }
    }
  }
  size--;
}
int** combinationSum3(int k, int n, int** columnSizes, int* returnSize)
{
  int candidates[] = {1,2,3,4,5,6,7,8,9};
  *returnSize = 0;

  size = 0;
  a = malloc(sizeof(int*));
  *columnSizes = malloc(sizeof(int));

  _combinationSum3(candidates, 0, k, n, columnSizes, returnSize);

  if (*returnSize == 0) {
    free(a);
    a = NULL;
  }

  return a;
}
int main(int argc, char **argv)
{
  int target;
  int limit;
  int **ans;
  int *columnSizes;
  int returnSize = 0;

  if (argc != 3)
    return 0;

  limit = atoi(argv[1]);
  target = atoi(argv[2]);

  ans = combinationSum3(limit, target, &columnSizes, &returnSize);

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
