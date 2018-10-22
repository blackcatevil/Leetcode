#include <stdio.h>
#include <stdlib.h>

char *stack = NULL;
unsigned int top;
unsigned int len;

int inline _isEmpty()
{
  return stack[0] == '\0'? 1:0;
}

void inline _push()
{
  stack[top++] = '(';
  return;
}

int inline _pop()
{
  if (_isEmpty())
    return -1;

  stack[--top] = '\0';
  return 0;
}

int longestValidParentheses(char* s)
{
  int left = 0, right = 0;
  int max_len = 0, tmp_pairs = 0, cur_pairs = 0;

  len = strlen(s);
  if (len < 2)
    return 0;

  stack = (char*)malloc(sizeof(char)*len);
  memset(stack, 0, sizeof(char)*len);
  top = 0;

  for (int i = 0; i < strlen(s); i++) {
    if (s[i] == '(') {
      _push();
      tmp_pairs += cur_pairs;
      if (tmp_pairs > max_pairs)
	max_pairs = tmp_pairs;
      cur_pairs = 0;
      tmp_pairs = 0;
    } else {
      if (_pop() < 0) {
	continue;
      } else {
	cur_pairs++;
      }
    }
  }

  if (tmp_pairs > 0) {
    if (_isEmpty()) {
      cur_pairs += tmp_pairs;
    } else {
      
    }
  }

  return max_len;
}

int main(int argc, char **argv)
{
  int len;

  if (argc != 2)
    return 0;

  len = longestValidParentheses(argv[1]);
  printf("%d\n", len);

  return 0;
}
