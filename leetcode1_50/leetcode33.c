#include <stdlib.h>
#include <stdio.h>

int _search(int* nums, int front, int end, int target)
{
  int mid, index;

  if (front < end) {
    mid = (front+end)/2;
    index = _search(nums, front, mid, target);
    return index >= 0? index: _search(nums, mid+1, end, target);
  }

  return nums[front] == target? front: -1;
}
int search(int* nums, int numsSize, int target)
{
  return numsSize == 0? -1: _search(nums, 0, numsSize-1, target);
}

int main()
{
  int nums[] = {4,5,6,7,0,1,2};
  int target = 3;

  printf("%d\n", search(nums, sizeof(nums)/sizeof(int), target));

  return 0;
}
