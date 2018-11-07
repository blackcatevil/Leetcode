#include <stdlib.h>
#include <stdio.h>

int** generateMatrix(int n)
{
  int **matrix;
  int index = 1;
  int i, j, k, m, l;

  if (n <= 0)
    return NULL;

  matrix = malloc(sizeof(int*)*n);
  for (i = 0; i < n; i++)
    matrix[i] = malloc(sizeof(int)*n);

  for (i = 0; i <= (n-1)/2 ; i++) {
    for (j = 0; j < n-i*2; j++)
      matrix[i][i+j] = index++;
    j--;

    for (k = 1; k < n-i*2; k++)
      matrix[i+k][i+j] = index++;
    k--;

    for (m = 1; m < n-i*2 && k != 0; m++)
      matrix[i+k][i+j-m] = index++;
    m--;

    for (l = 1; l < n-1-i*2 && m != 0; l++)
      matrix[i+k-l][i+j-m] = index++;
  }

  return matrix;
}

int main(int argc, char *argv[])
{
  int** matrix;
  int n;

  if (argc != 2)
    return -1;

  n = atoi(argv[1]);
  matrix = generateMatrix(n);

  for (int i = 0; i < n; i++) {
    printf("[");
    for (int j = 0; j < n; j++) {
      printf("%d", matrix[i][j]);
      if (j != n-1)
	printf("\t");
    }
    printf("]\n");
    free(matrix[i]);
  }
  free(matrix);

  return 0;
}
