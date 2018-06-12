#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PUSH 0
#define CLEAN 1
#define RETURN_LEN 2
#define IS_REPEAT 3
#define SAVE 4

char temp[64] = {0};
char ans[64] = {0};
int idx = 0;
int operation(char *c, int op)
{
  int ret;
  char k[1];
  
  switch (op) {
    case PUSH:
      temp[idx] = *c;
      idx++;
      break;
    case CLEAN:
      for (int i = 0; i < 64; i++)
        temp[i] = '\0';
      idx = 0;
      break;
    case RETURN_LEN:
      printf("ans = %s\n", ans);
      ret = strlen(ans);
      for (int i = 0; i < 64; i++) {
	temp[i] = ans[i] = '\0';
      }
      idx = 0;
      return ret;
    case SAVE:
      if (strlen(ans) <= strlen(temp))
        sprintf(ans, "%s", temp);
      break;
    default:
      break;
  }

  return 0;
}
int longestOfSubstringWithoutReaptChar(char *str)
{
  char *tmp = str;
  char c[2] = {0};
  char *k;
  if (*str == '\0')
    return operation(NULL, RETURN_LEN);

  do {
    operation(tmp, PUSH);
    tmp++;
    c[0] = *tmp;

    if (strstr(temp, c) != NULL) {
      operation(NULL, SAVE);
      operation(NULL, CLEAN);
      k = strstr(str, c);
      return longestOfSubstringWithoutReaptChar(++k);
    }

  }
  while (*tmp != '\0');

  operation(NULL, SAVE);
  operation(NULL, CLEAN);

  return operation(NULL, RETURN_LEN);
}

int main(int argc, char **argv)
{
  int ans;

  if (argc != 2) {
    printf("Usage: test-util [string]\n");
    return -1;
  }

  ans = func(argv[1]);
  printf("%d\n", ans);

  return 0;
}
