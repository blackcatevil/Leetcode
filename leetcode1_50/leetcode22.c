#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char** generateParenthesis(int n, int* returnSize)
{
  char **ans = malloc(sizeof(char*));
  char *tmp;
  int i = 0, j = 0, size = 0;

  if (n == 0) {
    free(ans);
    *returnSize = 0;
    return NULL;
  }

  // generate the first parentesis
  tmp = malloc(sizeof(char)*n*2);
  for (i = 0; i < n; i++)
    tmp[i] = '(';
  for (j = i; j < i+n; j++)
    tmp[j] = ')';
  size++;
  ans[size-1] = tmp;

  for (i = 1; i < n; i++) {
    tmp = malloc(sizeof(char)*n*2);
    strncpy(tmp, ans[size-1], n*2);
    find_and_swap(tmp);

  }

  *returnSize = size;
  return ans;
}

int main(int argc, char **argv)
{
  char **ans;
  int size;

  if (argc != 2)
    return 0;

  ans = generateParenthesis(atoi(argv[1]), &size);

  printf("[\n");
  for (int i = 0; i < size; i++) {
    printf(" \"");
    for (int j = 0; j < strlen(ans[i]); j++)
      printf("%c", ans[i][j]);
    printf("\"\n");
    free(ans[i]);
  }
  printf("]\n");
  free(ans);

  return 0;
}
