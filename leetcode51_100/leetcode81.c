#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool _search(int* nums, int front, int end, int target)
{
  int mid;

  if (front < end) {
    mid = (front+end)/2;
    if (nums[mid] == target)
      return true;
    return _search(nums, front, mid, target)? true: _search(nums, mid+1, end, target);
  }

  return nums[front] == target? true: false;
}
bool search(int* nums, int numsSize, int target)
{
  return numsSize == 0? false: _search(nums, 0, numsSize-1, target);
}

int main()
{
  int nums[] = {2,5,6,0,0,1,2};
  int target = 4;

  printf("%s\n", search(nums, sizeof(nums)/sizeof(int), target)?"True":"False");

  return 0;
}
