#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool canJump(int* nums, int numsSize)
{
  int last = numsSize-1;

  for (int i = numsSize-1; i >= 0; i--) {
    if (i+nums[i] >= last)
      last = i;
  }

  return last == 0;
}

int main()
{
  int nums[] = {2,0,6,9,8,4,5,0,8,9,1,2,9,6,8,8,0,6,3,1,2,2,1,2,6,5,3,1,2,2,6,4,2,4,3,0,0,0,3,8,2,4,0,1,2,0,1,4,6,5,8,0,7,9,3,4,6,6,5,8,9,3,4,3,7,0,4,9,0,9,8,4,3,0,7,7,1,9,1,9,4,9,0,1,9,5,7,7,1,5,8,2,8,2,6,8,2,2,7,5,1,7,9,6};
  int size = sizeof(nums)/sizeof(int);

  printf("%s\n", canJump(nums, size) == true? "True": "False");
  return 0;
}
