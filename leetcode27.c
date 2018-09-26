#include <stdlib.h>
#include <stdio.h>

int removeElement(int* nums, int numsSize, int val)
{
  int ans = 0;

  if (numsSize == 0)
    return 0;

  for (int i = 0; i < numsSize; i++) {
    if ((nums[i]^val) != 0) {
      nums[ans] = nums[i];
      ans++;
    }
  }

  return ans;
}

int main(int argc, char **argv)
{
  int input[] = {0,1,2,2,0,3,4,2};
  int val = 2;
  int size = sizeof(input)/sizeof(int);
  int len = removeElement(input, size, val);

  printf("[");
  for (int i = 0; i < len; i++)
    printf("%d ", input[i]);
  printf("]\n");

  return 0;
}
