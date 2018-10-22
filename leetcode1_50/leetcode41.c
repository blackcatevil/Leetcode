#include <stdlib.h>
#include <stdio.h>

int firstMissingPositive(int* nums, int numsSize)
{
  int index, tmp;

  if (numsSize == 0)
    return 1;

  for (int i = 0; i < numsSize; i++) {
    index = nums[i]-1;
    while (index >= 0 && index < numsSize && index != nums[index]-1) {
      tmp = index;
      index = nums[tmp]-1;
      nums[tmp] = tmp+1;
    }
  }

  for (index = 0; index < numsSize; index++) {
    if (nums[index]-1 != index)
      break;
  }

  return index+1;
}
int main()
{
  int nums[] = {3, 4, -1, 1};

  printf("%d\n", firstMissingPositive(nums, sizeof(nums)/sizeof(int)));

  return 0;
}
