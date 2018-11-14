#include <stdlib.h>
#include <stdio.h>

struct My_Interval {
  int start;
  int end;
};

struct My_Interval* merge(struct My_Interval* intervals, int intervalsSize, int* returnSize)
{
  struct My_Interval* ans;
  int size = 0;

  *returnSize = 0;
  if (intervalsSize == 0)
    return NULL;

  ans = malloc(sizeof(struct My_Interval));
  *returnSize = 1;
  if (intervalsSize == 1) {
    ans[0] = intervals[0];
    return ans;
  }

  for (int i = 0; i < intervalsSize-1; i++) {
    if (intervals[i].end >= intervals[i+1].start) {
      intervals[i+1].start = intervals[i].start;
      if (intervals[i].end > intervals[i+1].end)
	intervals[i+1].end = intervals[i].end;
    } else {
      size++;
      ans = (struct My_Interval*)realloc(ans, sizeof(struct My_Interval)*size);
      ans[size-1] = intervals[i];
    }
  }

  size++;
  ans = (struct My_Interval*)realloc(ans, sizeof(struct My_Interval)*size);
  ans[size-1] = intervals[intervalsSize-1];

  *returnSize = size;
  return ans;
}

int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration)
{
  int poison_time = 0;
  int size;
  struct My_Interval* arr;
  struct My_Interval* tmp;

  if (timeSeriesSize == 0)
    return 0;

  tmp = malloc(sizeof(struct My_Interval)*timeSeriesSize);
  for (int i = 0; i < timeSeriesSize; i++) {
    tmp[i].start = timeSeries[i];
    tmp[i].end = timeSeries[i] + duration-1;
  }
  
  arr = merge(tmp, timeSeriesSize, &size);
  free(tmp);

  for (int i = 0; i < size; i++)
    poison_time += (arr[i].end - arr[i].start + 1);
  free(arr);

  return poison_time;
}

int main()
{
  int time[] = {1,4};
  int size = sizeof(time)/sizeof(int);
  int duration = 2;

  printf("%d\n", findPoisonedDuration(time, size, duration));

  return 0;
}
