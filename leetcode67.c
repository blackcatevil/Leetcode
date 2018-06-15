#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* addBinary(char *a, char *b)
{
  size_t index_a = strlen(a)-1;
  size_t index_b = strlen(b)-1;
  int carry = 0;
  int i = 0;
  int head, end;
  size_t size_ans = strlen(a) > strlen(b)? strlen(a): strlen(b);
  char *ans = malloc(sizeof(char)*(size_ans+2));

  for (int j = 0; j < size_ans+1; j++)
    ans[j] = '0';
  ans[size_ans] = '\0';

  do {
    ans[i++] = ((a[index_a] - '0') ^ (b[index_b] - '0') ^ carry) + '0';
    carry = ((a[index_a] - '0') + (b[index_b] - '0') + carry) / 2;
    if (index_a == 0) {
      while (index_b > 0) {
	index_b--;
      	ans[i++] = ((b[index_b] - '0') ^ carry) + '0';
	carry = ((b[index_b] - '0') & carry);
      }
      ans[i] = carry + '0';
      break;
    }

    if (index_b == 0) {
      while (index_a > 0) {
	index_a--;
      	ans[i++] = ((a[index_a] - '0') ^ carry) + '0';
	carry = ((a[index_a] - '0') & carry);
      }
      ans[i] = carry + '0';
      break;
    }

    index_a--;
    index_b--;
  } while(1);

  head = 0;
  end = size_ans;
  while (end > head) {
    ans[head] = ans[head]^ans[end];
    ans[end] = ans[head]^ans[end];
    ans[head] = ans[head]^ans[end];
    head++;
    end--;
  }
  while (*ans == '0' && *(ans+1) != '\0')
    ans++;

  return ans;
}

int main()
{
  char *ans = addBinary("1101", "111");

  printf("%s\n", ans);
  free(ans);

  return 0;
}
