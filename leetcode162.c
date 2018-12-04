#include <stdlib.h>
#include <stdio.h>

int _findPeakElement(int* nums, int front, int end, int numsSize)
{
  int mid, index;

  if (front < end) {
    mid = (front+end)/2;
    index = _findPeakElement(nums, front, mid, numsSize);
    return index >= 0? index: _findPeakElement(nums, mid+1, end, numsSize);
  }

  if (front == 0)
    return nums[front] > nums[front+1]? front: -1;
  if (front == numsSize-1)
    return nums[front] > nums[front-1]? front: -1;
  if (nums[front] > nums[front+1] && nums[front] > nums[front-1])
    return front;
  return -1;
}

int findPeakElement(int* nums, int numsSize)
{
  return numsSize == 1? 0: _findPeakElement(nums, 0, numsSize-1, numsSize);
}

int main()
{
  int arr[] = {1, 2, 3, 1};

  printf("%d\n", findPeakElement(arr, sizeof(arr)/sizeof(int)));

  return 0;
}
