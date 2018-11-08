#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/* solution of problem#33 */ 
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

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target)
{
  int i;

  if (matrixRowSize == 0 || matrixColSize == 0)
    return false;

  for (int i = matrixRowSize-1 ; i >= 0; i--) {
    if (matrix[i][0] <= target && matrix[i][matrixColSize-1] >= target)
      if (search(matrix[i], matrixColSize, target) >= 0)
	return true;
  }

  return false;
}

int main()
{
  return 0;
}
