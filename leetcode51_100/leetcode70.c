#include <stdio.h>
#include <stdlib.h>

int climbStairs(int n)
{
  int *fib = malloc(sizeof(int)*(n+1));
  int ans;

  fib[0] = 1;
  fib[1] = 1;
  for (int i = 2; i <=n ; i++)
      fib[i] = fib[i-1] + fib[i-2];

  ans = fib[n];
  free(fib);

  return ans;
}

int main(int argc, char *argv[])
{
  if (argc != 2)
    return -1;

  printf("%d steps to top.\n", climbStairs(atoi(argv[1])));

  return 0;
}
