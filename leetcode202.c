#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int digitsPowerSum(int n)
{
  int sum = 0;

  while (n != 0) {
    sum += (n%10)*(n%10);
    n /= 10;
  }

  return sum;
}

bool isHappy(int n)
{
  int x = n;
  int y = n;

  do {
    x = digitsPowerSum(x);
    y = digitsPowerSum(digitsPowerSum(y));
  } while (x != y);

  return x == 1? true: false;
}
int main(int argc, char* argv[])
{
  if (argc != 2)
    return -1;

  printf("%s\n", isHappy(atoi(argv[1]))? "True": "False");

  return 0;
}
