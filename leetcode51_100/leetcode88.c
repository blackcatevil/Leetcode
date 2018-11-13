#include <stdio.h>
#include <stdlib.h>

void merge(int* nums1, int m, int* nums2, int n)
{
  int i = m-1, j = n-1, k = m+n-1;
  while (i >= 0 && j >= 0) {
    if (nums1[i] > nums2[j])
      nums1[k--] = nums1[i--];
    else
      nums1[k--] = nums2[j--];
  }
  if (i < 0) {
    while (k >= 0)
      nums1[k--] = nums2[j--];
  } else {
    while (k >= 0)
      nums1[k--] = nums1[i--];
  }
  return;
}

int main()
{
  int nums1[] = {3,4,6,0,0,0,0};
  int nums2[] = {1,2,5,7};
  int n = sizeof(nums2)/sizeof(int);
  int m = sizeof(nums1)/sizeof(int)-n;

  merge(nums1, m , nums2, n);

  for (int i = 0; i < sizeof(nums1)/sizeof(int); i++)
    printf("%d ", nums1[i]);
  printf("\n");

  return 0;
}
