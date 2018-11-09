#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
  int* ans;
  int carry = 1;

  if (digitsSize == 0)
    return NULL;

  ans = malloc(sizeof(int)*digitsSize);
  *returnSize = digitsSize;
  for (int i = digitsSize-1; i >= 0; i--) {
    int tmp = digits[i] + carry;
    ans[i] = tmp%10;
    carry = tmp/10;
  }

  if (carry == 1) {
    (*returnSize)++;
    ans = (int*)realloc(ans, sizeof(int)*(digitsSize+1));
    memset(ans, 0, sizeof(int)*(digitsSize+1));
    ans[0] = 1;
  }

  return ans;
}

int main()
{
  int nums[] = {9,9};
  int size = sizeof(nums)/sizeof(int);
  int returnSize;
  int* ans;

  ans = plusOne(nums, size, &returnSize);
  for (int i = 0; i < size; i++)
    printf("%d", nums[i]);
  printf(" + 1 = ");
  for (int i = 0; i < returnSize; i++)
    printf("%d", ans[i]);
  printf("\n");
  free(ans);

  return 0;
}
