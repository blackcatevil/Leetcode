#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* convert(char *s, int numRows)
{
  int len, i, j, k, index;
  int d = 2*(numRows-1);
  char *p;

  if (numRows < 2)
    return s;

  len = strlen(s);
  if (len == 0)
    return s;

  p = malloc(sizeof(char)*len+1);
  memset(p, 0, len+1);

  j = 0;
  for (i = 0; i < numRows; i++) {
    k = 0;
    while (1) {
      index = i + d*k;
      if (index < len) {
        p[j++] = s[index];
      } else {
	break;
      }

      index = i + 2*(numRows-i-1) + d*k;
      if (index < len) {
        p[j++] = s[index];
      } else {
	break;
      }
      if (i == 0 || i == numRows-1) {
	p[--j] = '\0';
      }

      k++;
    }
  }

  return p;
}

int main(int argc, char **argv)
{
  char *p;

  if (argc != 3)
    return 0;

  p = convert(argv[1], atoi(argv[2]));
  printf("%s\n", p);
  free(p);

  return 0;
}
