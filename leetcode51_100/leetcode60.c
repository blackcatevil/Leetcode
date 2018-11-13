#include <stdio.h>
#include <stdlib.h>

int find_j(int* nums, int front, int numsSize)
{
  for (int i = numsSize-1; i > front; i--) {
    if (nums[i] > nums[front])
      return i;
  }
  return -1;
}

void my_reverse(int* nums, int front, int numsSize)
{
  int tmp;

  for (int i = front, j = numsSize-1; i < j; i++, j--) {
    tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
  }
}

void nextPermutation(int* nums, int numsSize)
{
  int i, j, index;
  int tmp;

  for (index = numsSize-1; index > 0; index--) {
    if (nums[index] > nums[index-1]) {
      i = index-1;
      j = find_j(nums, i, numsSize);
      if (j < 0) {
	printf("Unexpected condition\n");
	return;
      }

      tmp = nums[i];
      nums[i] = nums[j];
      nums[j] = tmp;

      break;
    }
  }
  my_reverse(nums, index, numsSize);

  return;
}
char* getPermutation(int n, int k)
{
  char *str = malloc(sizeof(char)*(n+1));
  int *ans = malloc(sizeof(int)*n);

  for (int i = 0; i < n; i++)
    ans[i] = (i+1);

  for (int i = 1; i < k; i++)
    nextPermutation(ans, n);

  for (int i = 0; i < n; i++)
    str[i] = ans[i] + '0';
  str[n] = '\0';
  free(ans);

  return str;
}
int main(int argc, char *argv[])
{
  char *ans;

  if (argc != 3)
    return 0;

  ans = getPermutation(atoi(argv[1]), atoi(argv[2]));
  printf("%s\n", ans);
  free(ans);

  return 0;
}
