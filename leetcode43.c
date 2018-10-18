#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* multiply(char* num1, char* num2)
{
  int carry, d, k;
  int len1 = strlen(num1);
  int len2 = strlen(num2);
  char *ans, *tmp;

  if (num1 == NULL || num2 == NULL)
    return NULL;

  if ((num1[0] == '1' && len1 == 1) || (num2[0] == '0' && len2 == 1))
    return num2;
  if ((num2[0] == '1' && len2 == 1) || (num1[0] == '0' && len1 == 1))
    return num1;

  tmp = malloc(sizeof(char)*(len1+len2));
  memset(tmp, '0', sizeof(char)*(len1+len2));
  for (int i = len1-1; i >= 0; i--) {
    for (int j = len2-1; j >= 0; j--) {
      d = ((num1[i]-'0') * (num2[j]-'0') + (tmp[i+j+1]-'0'))%10;
      carry =  ((num1[i]-'0') * (num2[j]-'0') + (tmp[i+j+1]-'0'))/10;
      tmp[i+j+1] = d + '0';
      if (carry != 0)
	tmp[i+j] = ((tmp[i+j]-'0') + carry) + '0';
    }
  }

  k = 0;
  while (tmp[k] == '0')
    k++;

  ans = malloc(sizeof(char)*(len1+len2-k+1));
  strncpy(ans, tmp+k, len1+len2-k);
  ans[len1+len2-k] = '\0';
  free(tmp);

  return ans;
}

int main(int argc, char *argv[])
{
  char *ans;

  if (argc != 3)
    return 0;

  ans = multiply(argv[1], argv[2]);
  printf("%s * %s = %s\n", argv[1], argv[2], ans);
  free(ans);

  return 0;
}
