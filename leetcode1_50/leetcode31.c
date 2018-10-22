#include <stdio.h>
#include <stdlib.h>

int find_j(int* nums, int front, int numsSize)
{
  for (int i = numsSize-1; i > front; i--) {
    if (nums[i] > nums[front])
      return i;
  }
  return -1;
}

void my_reverse(int* nums, int front, int numsSize)
{
  int tmp;

  for (int i = front, j = numsSize-1; i < j; i++, j--) {
    tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
  }
}

void nextPermutation(int* nums, int numsSize)
{
  int i, j, index;
  int tmp;

  for (index = numsSize-1; index > 0; index--) {
    if (nums[index] > nums[index-1]) {
      i = index-1;
      j = find_j(nums, i, numsSize);
      if (j < 0) {
	printf("Unexpected condition\n");
	return;
      }

      tmp = nums[i];
      nums[i] = nums[j];
      nums[j] = tmp;

      break;
    }
  }
  my_reverse(nums, index, numsSize);

  return;
}

int main()
{
  int input[] = {3,2,1};
  int size = sizeof(input)/sizeof(int);

  nextPermutation(input, size);

  printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", input[i]);
        if (i != size-1)
          printf(", ");
      }
  printf("]\n");

  return 0;
}
