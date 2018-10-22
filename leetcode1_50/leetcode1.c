#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target)
{
  int *ans = malloc(sizeof(int)*2);
  int key;

  for (int i = 0; i < numsSize-1; i++) {
    key = target - nums[i];
    for (int j = i+1; j < numsSize; j++) {
      if (nums[j] == key) {
	ans[0] = i;
	ans[1] = j;
	goto end;
      }
    }
  }

end:
  return ans;
}

int main()
{
  int *ans = NULL;
  int input[4] = {2, 5, 7, 11};

  ans = twoSum(input, sizeof(input)/sizeof(int), 9);
  printf("[%d, %d]\n", ans[0], ans[1]);
  free(ans);

  return 0;
}
