#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char *stack = NULL;
unsigned int top;
unsigned int len;

int _isEmpty()
{
    return stack[0] == 0;
}

int _isFull()
{
    return stack[len-1] != 0;
}

int _push(char c)
{
  if (_isFull())
    return -1;

  stack[top++] = c;

  return 0;
}

int _pop(char c)
{
  if (_isEmpty())
    return -1;

  switch (c)
  {
    case ')':
      if (stack[top-1] != '(')
	return -1;
      break;
    case ']':
      if (stack[top-1] != '[')
	return -1;
      break;
    case '}':
      if (stack[top-1] != '{')
	return -1;
      break;
    default:
      return -1;
  }

  stack[--top] = 0;

  return 0;
}

bool isValid(char *s)
{
  int ret;

  len = strlen(s);
  stack = malloc(sizeof(char)*len);
  memset(stack, 0, len);
  top = 0;

  for (int i = 0; i < len; i++) {
    if (s[i] == ')' || s[i] == ']' || s[i] == '}')
      ret = _pop(s[i]);
    else
      ret = _push(s[i]);

    if (ret < 0)
      return false;
  }

  ret = _isEmpty();
  free(stack);

  return ret;
}

int main(int argc, char **argv)
{
  for (int i = 1; i < argc; i++)
    printf("%s\n", isValid(argv[i])? "True":"False");

  return 0;
}
