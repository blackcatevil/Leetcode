#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>

int arrangeCoins(int n)
{
  int i = (int)sqrt((double)n);

  while (i != INT_MAX) {
    if ((double)i/2 > (double)n/(i+1))
      return i-1;
    i++;
  }

  return 0;
}

int main(int argc, char* argv[])
{
  if (argc != 2)
    return -1;

  printf("%d\n", arrangeCoins(atoi(argv[1])));
  
  return 0;
}
