#include <stdlib.h>
#include <stdio.h>

int removeDuplicates(int* nums, int numsSize)
{
  int ans = 1;
  int count = 0;

  if (numsSize == 0)
    return 0;

  for (int i = 0; i < numsSize-1; i++) {
    if ((nums[i]^nums[i+1]) != 0) {
      nums[ans] = nums[i+1];
      ans++;
      count = 0;
    } else {
      if (count < 1) {
        nums[ans] = nums[i+1];
        ans++;
        count++;
      }
    }
  }

  return ans;
}

int main(int argc, char **argv)
{
  int input[] = {0,0,0,0,1,1,1,2,3,3,4,4,4};
  int size = sizeof(input)/sizeof(int);
  int len = removeDuplicates(input, size);

  printf("[");
  for (int i = 0; i < len; i++)
    printf("%d ", input[i]);
  printf("]\n");

  return 0;
}
