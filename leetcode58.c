#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void my_reverse(char* s)
{
  char tmp;

  for (int i = 0, j = strlen(s)-1; i < j; i++, j--) {
    tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
  }
}

int lengthOfLastWord(char* s)
{
  int i, j;

  my_reverse(s);

  i = 0;
  while (s[i] == ' ' && i < strlen(s)) {
    i++;
  }
  j = i;
  while (s[j] != ' ' && j < strlen(s)) {
    j++;
  }

  return j - i;
}

int main(int argc, char *argv[])
{
  if (argc != 2)
    return 0;

  printf("%d\n", lengthOfLastWord(argv[1]));
  return 0;
}
