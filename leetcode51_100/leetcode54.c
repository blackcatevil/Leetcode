#include <stdlib.h>
#include <stdio.h>

#define min(x, y) ((x) > (y)? (y): (x))

int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize)
{
  int *ans;;
  int index = 0;
  int i, j, k, m, n;

  if (matrixRowSize <= 0 || matrixColSize <= 0)
    return NULL;

  ans = malloc(sizeof(int)*matrixRowSize*matrixColSize);
  for (i = 0; i <= min((matrixRowSize-1)/2, (matrixColSize-1)/2); i++) {
    for (j = 0; j < matrixColSize-i*2; j++)
      ans[index++] = matrix[i][i+j];
    j--;

    for (k = 1; k < matrixRowSize-i*2; k++)
      ans[index++] = matrix[i+k][i+j];
    k--;

    for (m = 1; m < matrixColSize-i*2 && k != 0; m++)
      ans[index++] = matrix[i+k][i+j-m];
    m--;

    for (n = 1; n < matrixRowSize-1-i*2 && m != 0; n++)
      ans[index++] = matrix[i+k-n][i+j-m];
  }

  return ans;
}

int main()
{
  return 0;
}
