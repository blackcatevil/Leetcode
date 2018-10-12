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

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
  int *ans, size;

  if (nums1Size == 0 || nums2Size == 0) {
    *returnSize = 0;
    return NULL;
  }

  mergesort(nums1, 0, nums1Size-1);

  ans = malloc(sizeof(int));
  size = 0;
  for (int i = 0; i < nums1Size; i++) {
    if (i != 0 && nums1[i] == nums1[i-1])
      continue;

    for (int j = 0; j < nums2Size; j++) {
      if (nums1[i] == nums2[j]) {
	ans = realloc(ans, sizeof(int)*(++size));
	ans[size-1] = nums1[i];
	break;
      }
    }
  }

  *returnSize = size;
  return ans;
}

int main()
{
  int nums1[] = {4, 9, 5};
  int nums2[] = {9, 4, 9, 8, 4};
  int *ans;
  int returnSize;

  ans = intersection(nums1, sizeof(nums1)/sizeof(int), nums2, sizeof(nums2)/sizeof(int), &returnSize);
  
  printf("[");
  for (int i = 0; i < returnSize; i++) {
    printf("%d", ans[i]);
    if (i != returnSize-1)
      printf(", ");
  }
  printf("]\n");

  free(ans);
  return 0;
}
