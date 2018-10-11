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

int findContentChildren(int* g, int gSize, int* s, int sSize)
{
  int i = 0, j = 0;

  if (gSize == 0 || sSize == 0) {
    return 0;
  }

  mergesort(g, 0, gSize-1);
  mergesort(s, 0, sSize-1);

  while (i < gSize && j < sSize) {
    if (g[i] <= s[j])
      i++;
    j++;
  }

  return i;
}

int main()
{
  int nums1[] = {4, 9, 5};
  int nums2[] = {9, 4, 9, 8, 4};
  int ans;

  ans = findContentChildren(nums1, sizeof(nums1)/sizeof(int), nums2, sizeof(nums2)/sizeof(int));
  
  printf("%d\n", ans);
  return 0;
}
