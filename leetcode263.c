#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool isUgly(int num)
{
  if (num == 1)
    return true;
  if (num <= 0)
    return false;

  while (num != 1) {
    if (num%2 == 0)
      num /= 2;
    else if (num%3 == 0)
      num /= 3;
    else if (num%5 == 0)
      num /= 5;
    else
      return false;
  }

  return true;
}

int main(int argc, char* argv[])
{
  if (argc != 2)
    return -1;

  printf("%s\n", isUgly(atoi(argv[1]))? "True": "False");

  return 0;
}
