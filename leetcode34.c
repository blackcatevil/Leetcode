#include <stdlib.h>
#include <stdio.h>

int _searchFront(int* nums, int front, int end, int target)
{
  if (front < end) {
    int mid = (front+end)/2;
    if (nums[front] < target && nums[mid] < target)
      return _searchFront(nums, mid+1, end, target);
    else
      return _searchFront(nums, front, mid, target);
  }

  return nums[front] == target? front:-1;
}

int _searchEnd(int* nums, int front, int end, int target)
{
  if (front < end) {
    int mid = (front+end+1)/2;
    if (nums[end] > target && nums[mid] > target)
      return _searchEnd(nums, front, mid-1, target);
    else
      return _searchEnd(nums, mid, end, target);
  }

  return nums[end] == target? end:-1;
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
  int *ans = malloc(sizeof(int)*2);
  ans[0] = ans[1] = -1;
  *returnSize = 2;

  if (numsSize == 0)
    return ans; 

  ans[0] = _searchFront(nums, 0, numsSize-1, target);
  ans[1] = _searchEnd(nums, 0, numsSize-1, target);

  return ans;
}
int main()
{
  int nums[] = {5,6,7,7,9,9};
  int size = sizeof(nums)/sizeof(int);
  int target = 8;
  int returnSize;
  int *ans;

  ans = searchRange(nums, size, target, &returnSize);

  printf("[");
  for (int i = 0; i < returnSize; i++)
    printf("%d ", ans[i]);
  printf("]\n");
  free(ans);

  return 0;
}
