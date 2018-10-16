#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void _findMin(int* nums, int front, int end, int* min)
{
  int mid;

  if (front < end) {
    mid = (front+end)/2;
    _findMin(nums, front, mid, min);
    _findMin(nums, mid+1, end, min);
  } else {
    if (nums[front] < *min)
      *min = nums[front];
  }

  return;
}
int findMin(int* nums, int numsSize)
{
  int min = INT_MAX;

  _findMin(nums, 0, numsSize-1, &min);

  return min;
}

int main()
{
  int nums[] = {4,5,6,7,-100,1,2};

  printf("%d\n", findMin(nums, sizeof(nums)/sizeof(int)));

  return 0;
}
