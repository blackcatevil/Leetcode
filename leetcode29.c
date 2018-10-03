#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int divide1(int dividend, int divisor)
{
  int quotient = 0;
  int tmp_q, tmp_dividend = dividend, tmp_divisor = divisor;
  bool overflow = false;

  if (divisor == 1)
    return dividend;
  if (dividend == 0 || dividend < divisor)
    return 0;

  if (dividend == divisor)
    return 1;

  tmp_q = 1;
  while (tmp_dividend > tmp_divisor && !overflow) {
    tmp_dividend -= tmp_divisor;
    if (tmp_divisor > tmp_divisor << 1)
      overflow = true;
    tmp_divisor <<= 1;
    quotient += tmp_q;
    tmp_q <<= 1;
  }
  
  return quotient + divide1(tmp_dividend, divisor);
}

int divide2(int dividend, int divisor)
{
  int quotient = 0;
  int tmp_q, tmp_dividend = dividend, tmp_divisor = divisor;
  bool overflow = false;

  if (divisor == -1)
    return dividend == INT_MIN? INT_MAX:abs(dividend);
  if (dividend == 0 || dividend > divisor)
    return 0;

  if (dividend == divisor)
    return 1;

  tmp_q = 1;
  while (tmp_dividend < tmp_divisor && !overflow) {
    tmp_dividend -= tmp_divisor;
    if (tmp_divisor < tmp_divisor << 1)
      overflow = true;
    tmp_divisor <<= 1;
    quotient += tmp_q;
    tmp_q <<= 1;
  }
  
  return quotient + divide2(tmp_dividend, divisor);
}

int divide3(int dividend, int divisor)
{
  int quotient = 0;
  int tmp_q, tmp_dividend = dividend, tmp_divisor = divisor;
  bool overflow = false;

  if (divisor == -1)
    return -dividend;
  if (dividend == 0 || dividend + divisor < 0)
    return 0;

  if (dividend + divisor == 0)
    return -1;

  tmp_q = -1;
  while (tmp_dividend + tmp_divisor >= 0 && !overflow) {
    tmp_dividend += tmp_divisor;
    if (tmp_divisor < tmp_divisor << 1)
      overflow = true;
    tmp_divisor <<= 1;
    quotient += tmp_q;
    tmp_q <<= 1;
  }
  
  return quotient + divide3(tmp_dividend, divisor);
}

int divide4(int dividend, int divisor)
{
  int quotient = 0;
  int tmp_q, tmp_dividend = dividend, tmp_divisor = divisor;
  bool overflow = false;

  if (divisor == 1)
    return dividend;
  if (dividend == 0 || dividend + divisor > 0)
    return 0;

  if (dividend + divisor == 0)
    return -1;

  tmp_q = -1;
  while (tmp_dividend + tmp_divisor <= 0 && !overflow) {
    tmp_dividend += tmp_divisor;
    if (tmp_divisor > tmp_divisor << 1)
      overflow = true;
    tmp_divisor <<= 1;
    quotient += tmp_q;
    tmp_q <<= 1;
  }
  
  return quotient + divide4(tmp_dividend, divisor);
}
int divide(int dividend, int divisor)
{
  if (dividend >= 0 && divisor > 0)
    return divide1(dividend, divisor);
  else if (dividend <= 0 && divisor < 0)
    return divide2(dividend, divisor);
  else if (dividend >= 0 && divisor < 0)
    return divide3(dividend, divisor);
  else
    return divide4(dividend, divisor);
}
int main(int argc, char **argv)
{
  if (argc != 3)
    return 0;

  printf("%d\n", divide(atoi(argv[1]), atoi(argv[2])));

  return 0;
}
