#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void setZeroes(int** matrix, int matrixRowSize, int matrixColSize)
{
  int*zeroRow;

  if (matrixRowSize == 0 || matrixColSize == 0)
    return;

  zeroRow = malloc(sizeof(int)*matrixRowSize);
  memset(zeroRow, 0, sizeof(int)*matrixRowSize);

  for (int i = 0; i < matrixRowSize; i++) {
    for (int j = 0; j < matrixColSize; j++) {
      if (matrix[i][j] == 0) {
	for (int k = 0; k < i; k++)
	  matrix[k][j] = 0;
	zeroRow[i] = 1;
	continue;
      } else {
	if (matrix[0][j] == 0)
	  matrix[i][j] = 0;
      }
    }
  }

  for (int i = 0; i < matrixRowSize; i++) {
    if (zeroRow[i] == 1)
      memset(matrix[i], 0, sizeof(int)*matrixColSize);
  }
  free(zeroRow);

  return;
}

int main()
{
  return 0;
}
