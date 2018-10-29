#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int maxArea(int* height, int heightSize)
{
  int area, right, left;
  int max = INT_MIN;

  for (int i = 0; i < heightSize-1; i++) {
    left = height[i];
    for (int j = i+1; j < heightSize; j++) {
      right = height[j] > left? left: height[j];
      area = (j-i)*right;
      if (area > max)
	max = area;
    }
  }

  return max;
}
int main()
{
  int a[] = {1,8,6,2,5,4,8,3,7};

  printf("%d\n", maxArea(a, sizeof(a)/sizeof(int)));
  return 0;
}
