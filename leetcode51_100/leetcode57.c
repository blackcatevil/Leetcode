#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Interval {
  int start;
  int end;
};

void _merge(struct Interval* a, int front, int mid, int end)
{
  struct Interval *tmp;
  int size = end-front+1;
  int l = front, r = mid+1;
  
  tmp = malloc(sizeof(struct Interval)*size);

  for (int i = 0; i < size; i++) {
    if (r > end)
    	tmp[i] = a[l++];
    else if (l > mid)
        tmp[i] = a[r++];
    else if (a[l].start < a[r].start)
    	tmp[i] = a[l++];
    else
        tmp[i] = a[r++];
  }

  memcpy(a+front, tmp, sizeof(struct Interval)*size);
  free(tmp);
}

void mergesort(struct Interval* a, int front, int end)
{
  if (front < end) {
    int mid = (front+end)/2;
    mergesort(a, front, mid);
    mergesort(a, mid+1, end);
    _merge(a, front, mid, end);
  }
}

struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize)
{
  struct Interval* ans;
  int size = 0;

  *returnSize = 0;
  if (intervalsSize == 0)
    return NULL;

  ans = malloc(sizeof(struct Interval));
  *returnSize = 1;
  if (intervalsSize == 1) {
    ans[0] = intervals[0];
    return ans;
  }

  mergesort(intervals, 0, intervalsSize-1);

  for (int i = 0; i < intervalsSize-1; i++) {
    if (intervals[i].end >= intervals[i+1].start) {
      intervals[i+1].start = intervals[i].start;
      if (intervals[i].end > intervals[i+1].end)
	intervals[i+1].end = intervals[i].end;
    } else {
      size++;
      ans = (struct Interval*)realloc(ans, sizeof(struct Interval)*size);
      ans[size-1] = intervals[i];
    }
  }

  size++;
  ans = (struct Interval*)realloc(ans, sizeof(struct Interval)*size);
  ans[size-1] = intervals[intervalsSize-1];

  *returnSize = size;
  return ans;
}

struct Interval* insert(struct Interval* intervals, int intervalsSize, struct Interval newInterval, int* returnSize)
{
  struct Interval* ans;
  struct Interval* new;

  new = malloc(sizeof(struct Interval)*(intervalsSize+1));

  memcpy(new, intervals, sizeof(struct Interval)*intervalsSize);
  new[intervalsSize] = newInterval;

  ans = merge(new, intervalsSize+1, returnSize);
  free(new);

  return ans;
}

int main()
{
  return 0;
}
