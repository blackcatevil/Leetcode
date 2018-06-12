#include <stdlib.h>
#include <stdio.h>

int* twoSum(int *num, int numSize, int target, int* returnSize)
{
  int *ans = malloc(sizeof(int)*2);
  int head = 0;
  int tier = numSize - 1;

  while (num[head] + num[tier] != target) {
    if (head >= tier)
      return NULL;

    if (num[head] + num[tier] < target) {
      head++;
    }
    else {
      tier--;
    }
  }

  ans[0] = head;
  ans[1] = tier;
  *returnSize = sizeof(ans)/sizeof(int);

  return ans;
}

int main()
{
  int *ans = NULL;
  int size;
  int input[4] = {2 ,7, 11, 15};

  ans = twoSum(input, sizeof(input)/sizeof(int), 9, &size);
  printf("[%d, %d]\n", ans[0], ans[1]);
  free(ans);

  return 0;
}
