#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int combinationSum4(int* nums, int numsSize, int target)
{
  int *dp;
  int ret;

  if (numsSize == 0)
    return 0;

  dp = malloc(sizeof(int)*(target+1));
  memset(dp, 0, sizeof(int)*(target+1));
  dp[0] = 1;

  for (int i = 1; i <= target; i++) {
    for (int j = 0; j < numsSize; j++) {
      if (i-nums[j] >= 0)
	dp[i] += dp[i-nums[j]];
    }
  }
  ret = dp[target];
  free(dp);

  return ret;
}
int main()
{
  int nums[] = {1,2,3};
  int target = 32;
  int numsSize = sizeof(nums)/sizeof(int);

  printf("%d\n", combinationSum4(nums, numsSize, target));

  return 0;
}
