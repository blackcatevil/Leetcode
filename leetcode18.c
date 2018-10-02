#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void merge(int* a, int front, int mid, int end)
{
  int *tmp;
  int size = end-front+1;
  int l = front, r = mid+1;
  
  tmp = malloc(sizeof(int)*size);

  for (int i = 0; i < size; i++) {
    if (r > end) {
    	tmp[i] = a[l++];
    } else if (l > mid) {
        tmp[i] = a[r++];
    } else if (a[l] < a[r]) {
    	tmp[i] = a[l++];
    } else {
        tmp[i] = a[r++];
    }
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

int** threeSum(int* nums, int numsSize, int target, int* returnSize)
{
  int sum, size = 0;
  int *ptr = NULL, **ans = NULL;

  for (int i = 1; i < numsSize-2; i++) {
    if (i != 1 && nums[i] == nums[i-1]) {
      continue;
    }

    for (int j = i+1, k = numsSize-1; j < k;) {
      sum = nums[i] + nums[j] + nums[k];

      if (sum > target) {
	k--;
      } else if (sum == target){
	if (ptr != NULL &&
	    nums[i] == ptr[1] &&
	    nums[j] == ptr[2] &&
	    nums[k] == ptr[3]) {
	  j++;
	  continue;
	}
	size++;
	ptr = malloc(sizeof(int)*4);
	ptr[0] = nums[0];
	ptr[1] = nums[i];
	ptr[2] = nums[j];
	ptr[3] = nums[k];

	ans = (int**)realloc(ans, sizeof(int*)*size);
	ans[size-1] = ptr;
	j++;
      } else {
	j++;
      }
    }
  }

  *returnSize = size;

  return ans;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize)
{
  int size = 0, subsize = 0;
  int **ans = NULL, **tmp;

  if (numsSize == 0) {
    *returnSize = 0;
    return NULL;
  }

  mergesort(nums, 0, numsSize-1);

  for (int i = 0; i < numsSize-3; i++) {
    if (i != 0 && nums[i] == nums[i-1]) {
      continue;
    }

    tmp = threeSum(nums+i, numsSize-i, target-nums[i], &subsize);
    ans = (int**)realloc(ans, sizeof(int*)*(size+subsize));

    for (int j = 0; j < subsize; j++) {
      ans[size+j] = tmp[j];
    }

    size += subsize;
  }

  *returnSize = size;

  return ans;
}

int main()
{
  int **ans, size;
  int target = 0;
  int input[] = {-3, -2, -1, 0, 0, 1, 2, 3};

  ans = fourSum(input, sizeof(input)/sizeof(int), target, &size);

  printf("[\n");
  for (int i = 0; i < size; i++) {
    printf("  [");
    for (int j = 0; j < 4; j++) {
      printf("%d ", ans[i][j]);
    }
    printf("],\n");
    free(ans[i]);
  }
  printf("]\n");
  free(ans);

  return 0;
}
