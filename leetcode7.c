#include <stdlib.h>
#include <stdio.h>

int reverse(int x)
{
    int a = 0;
    int b;
    int tmp;

    while (x != 0) {
            b = x % 10;
            tmp = a*10 + b;
            if ((tmp - b)/10 != a)
                return 0;
            a = tmp;
            x /= 10;
        }

    return a;
}

int main()
{
  printf("%d\n", reverse(123));
  printf("%d\n", reverse(-123));
  printf("%d\n", reverse(2147483647));
  printf("%d\n", reverse(1534236469));

  return 0;
}
