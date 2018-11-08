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

  for (i = 0; i < matrixRowSize; i++) {
    if (matrix[i][0] > target) {
      break;
    }
  }
  if (i != 0)
    i--;

  return search(matrix[i], matrixColSize, target) < 0? false: true;
}

int main()
{
  return 0;
}
