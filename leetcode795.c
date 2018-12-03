#include <stdio.h>
#include <stdlib.h>

int numSubarray(int* A, int front, int end, int L)
{
  int total = ((end-front+2)*(end-front+1))/2;
  int l = -1, r = -1;

  if (end >= front) {
    for (int i = front; i <= end; i++) {
      if (A[i] < L) {
	if (l < 0)
	  l = i;
	r = i;
      } else {
	if (l >= 0 && r >= 0) {
	  total -= ((r-l+2)*(r-l+1))/2;
	  l = r = -1;
	}
      }
    }
    if (l >= 0 && r >= 0)
      total -= ((r-l+2)*(r-l+1))/2;

    return total;
  }

  return 0;
}

int _numSubarrayBoundedMax(int* A, int front, int end, int L, int R)
{
  int ans = 0;

  for (int i = front; i <= end; i++) {
    if (A[i] > R) {
      ans += _numSubarrayBoundedMax(A, front, i-1, L, R);
      ans += _numSubarrayBoundedMax(A, i+1, end, L, R);
      return ans;
    }
  }

  ans += numSubarray(A, front, end, L);

  return ans;
}

int numSubarrayBoundedMax(int* A, int ASize, int L, int R)
{
  return ASize > 0? _numSubarrayBoundedMax(A, 0, ASize-1, L, R): 0;
}

int main()
{
  int arr[] = {1, 2};
  int L = 2;
  int R = 3;

  printf("%d\n", numSubarrayBoundedMax(arr, sizeof(arr)/sizeof(int), L, R));
  return 0;
}
