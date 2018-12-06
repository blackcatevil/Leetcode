#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int mySqrt(int x)
{
  if (x == 0)
    return 0;

  for (int i = 1; i <= INT_MAX; i++) {
    if (i > x/i)
      return i-1;
  }

  return -1;
}

int main(int argc, char* argv[])
{
  if (argc != 2)
    return -1;

  printf("%d\n", mySqrt(atoi(argv[1])));

  return 0;
}
