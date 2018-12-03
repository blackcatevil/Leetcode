#include <stdio.h>
#include <stdlib.h>

int ColSum(int** M, int start, int end, int prevCol)
{
  int sum = 0;

  for (int i = start; i <= end; i++)
    sum += M[i][prevCol];

  return sum;
}

int RowSum(int** M, int start, int end, int prevRow)
{
  int sum = 0;

  for (int i = start; i <= end; i++)
    sum += M[prevRow][i];

  return sum;
}

int** imageSmoother(int** M, int MRowSize, int MColSize, int** columnSizes, int* returnSize)
{
  int** map;
  int** pixels;
  int start, end;

  // Init new image
  map = malloc(sizeof(int*)*MRowSize);
  pixels = malloc(sizeof(int*)*MRowSize);
  for (int i = 0; i < MRowSize; i++) {
    map[i] = malloc(sizeof(int)*MColSize);
    pixels[i] = malloc(sizeof(int)*MColSize);
  }
  
  // Init the first pixel
  map[0][0] = M[0][0];
  pixels[0][0] = 1;
  if (MRowSize > 1) {
    map[0][0] += M[1][0];
    pixels[0][0]++;
  }
  if (MColSize > 1) {
    map[0][0] += M[0][1];
    pixels[0][0]++;
  }
  if (MRowSize > 1 && MColSize > 1) {
    map[0][0] += M[1][1];
    pixels[0][0]++;
  }

  // Init the first Column
  start = 0;
  end = MColSize > 1? 1: 0; 
  for (int i = 1; i < MRowSize; i++) {
    map[i][0] = map[i-1][0];
    pixels[i][0] = pixels[i-1][0];
    if (i > 1) {
      map[i][0] -= RowSum(M, start, end, i-2);
      pixels[i][0] -= end-start+1;
    }
    if (i < MRowSize-1) {
      map[i][0] += RowSum(M, start, end, i+1);
      pixels[i][0] += end-start+1;
    }
  }

  // Dynamic programming
  for (int i = 0; i < MRowSize; i++) {
    start = i-1;
    end = i+1;
    for (int j = 1; j < MColSize; j++) {
      if (i == 0)
	start = i;
      if (i == MRowSize-1)
	end = i;

      map[i][j] = map[i][j-1];
      pixels[i][j] = pixels[i][j-1];
      if (j > 1) {
	map[i][j] -= ColSum(M, start, end, j-2);
	pixels[i][j] -= end-start+1;
      }
      if (j < MColSize-1) {
	map[i][j] += ColSum(M, start, end, j+1);
	pixels[i][j] += end-start+1;
      }
    }
  }

  // Smooth image and free pixels map
  for (int i = 0; i < MRowSize; i++) {
    for (int j = 0; j < MColSize; j++)
      map[i][j] /= pixels[i][j];
    free(pixels[i]);
  }
  free(pixels);

  *returnSize = MRowSize;
  *columnSizes = malloc(sizeof(int)*MRowSize);
  for (int i = 0; i < MRowSize; i++)
    (*columnSizes)[i] = MColSize;

  return map;
}

int main()
{
  return 0;
}
