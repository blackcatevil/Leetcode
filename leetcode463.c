#include <stdlib.h>
#include <stdio.h>

int islandPerimeter(int** grid, int gridRowSize, int gridColSize)
{
  int p, sum = 0;

  if (gridRowSize == 0)
    return 0;

  for (int i = 0; i < gridRowSize; i++) {
    for (int j = -1; j < gridColSize; j++) {
      if (j == -1)
	p = 0^grid[i][0];
      else if (j == gridColSize-1)
	p = 0^grid[i][j];
      else
	p = grid[i][j]^grid[i][j+1];
      sum += p;
    }
  }

  for (int i = 0; i < gridColSize; i++) {
    for (int j = -1; j < gridRowSize; j++) {
      if (j == -1)
	p = 0^grid[0][i];
      else if (j == gridRowSize-1)
	p = 0^grid[j][i];
      else
	p = grid[j][i]^grid[j+1][i];
      sum += p;
    }
  }

  return sum;
}

int main()
{
  return 0;
}
