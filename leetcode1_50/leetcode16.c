#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
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

int threeSumClosest(int* nums, int numsSize, int target)
{
  int min = INT_MAX;
  int sum;

  mergesort(nums, 0, numsSize-1);

  for (int i = 0; i < numsSize-2; i++) {
    if (i != 0 && nums[i] == nums[i-1])
      continue;

    for (int j = i+1, k = numsSize-1; j < k;) {
      sum = nums[i] + nums[j] + nums[k];

      if (sum > target)
	k--;
      else if (sum < target)
	j++;
      else
	return sum;
      
      if (min == INT_MAX || abs(sum-target) < abs(min-target))
	min = sum;
    }
  }

  return min;
}

int main()
{
  int a[] = {-3, -2, -5, 3, -4};
  int target = -1;

  printf("%d\n", threeSumClosest(a, sizeof(a)/sizeof(int), target));
  return 0;
}
