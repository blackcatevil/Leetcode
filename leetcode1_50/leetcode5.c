#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void addprefix(char *dst, char *src)
{
  int len = strlen(src);

  for (int i = 0; i < len; i++) {
      dst[i*2+1] = src[i];
      dst[i*2] = '#';
  }
  dst[len*2] = '#';

  return;
}

char* longestPalindrome(char* s)
{
  int len = strlen(s);
  int i, j, k, max_len, max_idx;
  int *d;
  char *tmp;

  if (len < 2)
    return s;

  tmp = malloc(sizeof(char)*2*len+1);
  memset(tmp, 0, len*2+1);

  d = malloc(sizeof(int)*2*len+1);
  for (i = 0; i < 2*len+1; i++)
    d[i] = 0;

  addprefix(tmp, s);

  max_len = max_idx = 0;
  for (k = 1; k < 2*len; k++) {
    i = k-1;
    j = k+1;
    while(i >= 0 && j < 2*len+1) {
      if (tmp[i] == tmp[j]) {
        d[k]++;
      } else {
	break;
      }
      i--;
      j++;
    }

    if (d[k] >= max_len) {
      max_len = d[k];
      max_idx = k;
    }
  }

  free(tmp);
  free(d);

  tmp = malloc(sizeof(char)*max_len+1);
  memset(tmp, 0, max_len+1);
  strncpy(tmp, s+(max_idx/2)-(max_len/2), max_len);

  return tmp;
}

int main(int argc, char **argv)
{
  char *p;

  if (argc < 2)
    return 0;

  for (int i = 1; i < argc; i++) {
    p = longestPalindrome(argv[i]);
    printf("%s\n", p);
    free(p);
  }

  return 0;
}
