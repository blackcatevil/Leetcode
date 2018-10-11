#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int* a, int front, int mid, int end)
{
  int *tmp;
  int size = end-front+1;
  int l = front, r = mid+1;
  
  tmp = malloc(sizeof(int)*size);

  for (int i = 0; i < size; i++) {
      if (r > end)
      	tmp[i] = a[l++];
      else if (l > mid)
        tmp[i] = a[r++];
      else if (a[l] < a[r])
      	tmp[i] = a[l++];
      else
        tmp[i] = a[r++];
  }

  memcpy(a+front, tmp, sizeof(int)*size);
  free(tmp);
}

void mergesort(int* a, int front, int end)
{
  if (front < end) {
      int mid = (front+end)/2;
      mergesort(a, front, mid);
      mergesort(a, mid+1, end);
      merge(a, front, mid, end);
  }
}

int minMoves2(int* nums, int numsSize)
{
  int mid_value;
  unsigned int moves = 0;

  if (numsSize == 0) {
    return 0;
  }

  mergesort(nums, 0, numsSize-1);

  mid_value = nums[numsSize/2];
  for (int i = 0; i < numsSize; i++) {
    moves += abs(nums[i] - mid_value);
  }

  return moves;
}

int main()
{
  int nums[] = {4, 9, 5};
  int ans;

  ans = minMoves2(nums, sizeof(nums)/sizeof(int));

  printf("%d\n", ans);
  
  return 0;
}
