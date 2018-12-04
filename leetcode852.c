#include <stdlib.h>
#include <stdio.h>

int _peakIndexInMountainArray(int* nums, int front, int end, int numsSize)
{
  int mid, index;

  if (front < end) {
    mid = (front+end)/2;
    index = _peakIndexInMountainArray(nums, front, mid, numsSize);
    return index >= 0? index: _peakIndexInMountainArray(nums, mid+1, end, numsSize);
  }

  if (front == 0)
    return nums[front] > nums[front+1]? front: -1;
  if (front == numsSize-1)
    return nums[front] > nums[front-1]? front: -1;
  if (nums[front] > nums[front+1] && nums[front] > nums[front-1])
    return front;
  return -1;
}

int peakIndexInMountainArray(int* nums, int numsSize)
{
  return numsSize == 1? 0: _peakIndexInMountainArray(nums, 0, numsSize-1, numsSize);
}

int main()
{
  int arr[] = {1, 2, 3, 1};

  printf("%d\n", peakIndexInMountainArray(arr, sizeof(arr)/sizeof(int)));

  return 0;
}
