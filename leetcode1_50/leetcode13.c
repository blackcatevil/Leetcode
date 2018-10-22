#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Roman2int(char c)
{
  switch(c) 
  {
    case 'I':
      return 1;
    case 'V':
      return 5;
    case 'X':
      return 10;
    case 'L':
      return 50;
    case 'C':
      return 100;
    case 'D':
      return 500;
    case 'M':
      return 1000;
  }
}

int main(int argc, char **argv)
{
  char *input, *p;
  int len, sum = 0;

  input = argv[1];
  len = strlen(input);

  if (len == 1)
    printf("%d\n", Roman2int(*input));

  p = input + len-1;

  while (p >= input) {
    sum += Roman2int(*p1);
    if (p != input && Roman2int(*(p-1)) < Roman2int(*p)) {
      sum -= Roman2int(*(p-1));
      p -= 2;
    } else {
      p -= 1;
    }
  }

  printf("%s = %d\n",input, sum);

  return 0;
}
