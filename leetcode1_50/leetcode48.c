#include <stdlib.h>
#include <stdio.h>

void _swap(int* a, int* b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void rotate(int** matrix, int matrixRowSize, int *matrixColSizes)
{
  for (int i = 0; i <= (matrixRowSize-1)/2; i++) {
    for (int j = 0; j < matrixRowSize-i*2-1; j++) {
      _swap(&matrix[i][i+j], &matrix[i+j][i+matrixRowSize-i*2-1]);
      _swap(&matrix[i][i+j], &matrix[i+matrixRowSize-i*2-1][i-j+matrixRowSize-i*2-1]);
      _swap(&matrix[i][i+j], &matrix[i-j+matrixRowSize-i*2-1][i]);
    }
  }
}

int main()
{
  return 0;
}
