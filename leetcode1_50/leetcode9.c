#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(int x)
{
  int a = 0, b;
  int y;

  if (x < 0)
    return false;
  if (x <= 9)
    return true;

  y = x;
  while (y > 0) {
    b = y % 10;
    a = a*10 + b;
    y /= 10;
  }

  return (x - a) != 0? false: true;
}

int main()
{
  printf("%s\n", isPalindrome(-121)? "True": "False");
  printf("%s\n", isPalindrome(12321)? "True": "False");
  printf("%s\n", isPalindrome(-3)? "True": "False");
  printf("%s\n", isPalindrome(0)? "True": "False");

  return 0;
}
