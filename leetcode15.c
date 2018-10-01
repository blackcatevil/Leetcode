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

int** threeSum(int* nums, int numsSize, int* returnSize)
{
  int target, prev_i, size;
  int *ptr = NULL, **ans = NULL;

  size = 0;

  if (numsSize == 0) {
    *returnSize = 0;
    return NULL;
  }

  mergesort(nums, 0, numsSize-1);
  for (int i = 0; i < numsSize; i++)
    printf("%d ", nums[i]);
  printf("\n");

  for (int i = 0; i < numsSize-2; i++) {
    if (i != 0 && nums[i] == nums[i-1])
      continue;

    for (int j = i+1, k = numsSize-1; j < k;) {
      target = nums[i] + nums[j] + nums[k];

      if (target > 0) {
	k--;
      } else if (target == 0){
	if (ptr != NULL &&
	    nums[i] == ptr[0] &&
	    nums[j] == ptr[1] &&
	    nums[k] == ptr[2]) {
	  j++;
	  continue;
	}
	size++;
	ptr = malloc(sizeof(int)*3);
	ptr[0] = nums[i];
	ptr[1] = nums[j];
	ptr[2] = nums[k];

	ans = (int*)realloc(ans, sizeof(int*)*size);
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

int main()
{
  int **ans, size;
  int input[] = {3, 0, -2, -1, 1, 2};

  ans = threeSum(input, sizeof(input)/sizeof(int), &size);

  printf("[\n");
  for (int i = 0; i < size; i++) {
    printf("  [");
    for (int j = 0; j < 3; j++) {
      printf("%d ", ans[i][j]);
    }
    printf("],\n");
    free(ans[i]);
  }
  printf("]\n");
  free(ans);

  return 0;
}
