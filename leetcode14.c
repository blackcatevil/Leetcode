#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void func(char *s1, char *s2, char *prefix)
{
  int len = strlen(s1) > strlen(s2)? strlen(s2):strlen(s1);
  size_t i;
  char *p1 = s1, *p2 = s2;

  for (i = 0; i < len; i++) {
    if (p1[i] != p2[i])
      break;
  }

  memset(prefix, 0, sizeof(char)*1024);
  strncpy(prefix, s2, i);

  return;
}

char* longestCommonPrefix(char** strs, int strsSize)
{
  char *prefix = malloc(sizeof(char)*1024);

  strcpy(prefix, strs[0]);

  if (strsSize == 1)
    return prefix;

  for (int i = 1; i < strsSize; i++)
    func(prefix, strs[i], prefix);

  return prefix;
}
int main(int argc, char **argv)
{
  char *prefix = longestCommonPrefix(argv+1, argc-1);
  printf("%s\n", prefix);
  free(prefix);
  return 0;
}
