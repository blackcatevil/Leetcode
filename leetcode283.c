#include <stdio.h>
#include <stdlib.h>

void moveZeroes(int* nums, int numsSize)
{
  int i = 0, j = 0;
  int tmp;

  while (j < numsSize) {
    if (nums[i] == 0 && nums[j] !=0) {
      tmp = nums[i];
      nums[i] = nums[j];
      nums[j] = tmp;
      i++;
      j++;
    }
    if (nums[i] != 0) {
      i++;
      j++;
    }
    if (nums[j] == 0) {
      j++;
    }
  }

  return;
}

int main()
{
  int nums[] = {4,2,4,0,0,3,0,5,1,0};
  int size = sizeof(nums)/sizeof(int);

  moveZeroes(nums, size);

  printf("[");
  for (int i = 0; i < size; i++) {
    printf("%d", nums[i]);
    if (i != size-1)
      printf(",");
  }
  printf("]\n");

  return 0;
}
