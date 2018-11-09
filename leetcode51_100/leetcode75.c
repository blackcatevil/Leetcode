#include <stdlib.h>
#include <stdio.h>

void sortColors(int* nums, int numsSize)
{
  int front = 0, rear = numsSize-1;
  int zeros = 0, ones = 0, twos = 0;

  for (int i = 0, j = numsSize-1; i <= j; i++, j--) {
    if (nums[i] == 0) zeros++;
    if (nums[j] == 0 && i != j) zeros++;
    if (nums[i] == 1) ones++;
    if (nums[j] == 1 && i != j) ones++;
    if (nums[i] == 2) twos++;
    if (nums[j] == 2 && i != j) twos++;

    if (zeros > 0) {
      nums[front++] = 0;
      zeros--;
    }
    if (twos > 0) {
      nums[rear--] = 2;
      twos--;
    }
  }

  while (zeros > 0) {
    nums[front++] = 0;
    zeros--;
  }
  while (twos > 0) {
    nums[rear--] = 2;
    twos--;
  }
  while (ones > 0) {
    nums[front++] = 1;
    ones--;
  }
  return;
}

int main()
{
  int nums[] = {1,1,1,1,0,0,0};
  int size = sizeof(nums)/sizeof(int);

  sortColors(nums, size);

  printf("[");
  for (int i = 0; i < size; i++)
    printf("%d ", nums[i]);
  printf("]\n");

  return 0;
}
