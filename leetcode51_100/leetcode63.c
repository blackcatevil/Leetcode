#include <stdlib.h>
#include <stdio.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize)
{
  if (obstacleGridRowSize == 0 ||
      obstacleGridColSize == 0 ||
      obstacleGrid[obstacleGridRowSize-1][obstacleGridColSize-1] == 1)
    return 0;

  obstacleGrid[obstacleGridRowSize-1][obstacleGridColSize-1] = 1;
  for (int i = obstacleGridRowSize-1; i >= 0; i--) {
    for (int j = obstacleGridColSize-1 ; j >= 0; j--) {
      if ( i == obstacleGridRowSize-1 && j ==obstacleGridColSize-1)
	continue;

      if (obstacleGrid[i][j] == 1) {
	obstacleGrid[i][j] = 0;
	continue;
      }

      if (i == obstacleGridRowSize-1) {
	obstacleGrid[i][j] += obstacleGrid[i][j+1];
      } else if (j == obstacleGridColSize-1) {
	obstacleGrid[i][j] += obstacleGrid[i+1][j];
      } else {
	obstacleGrid[i][j] = obstacleGrid[i][j] + obstacleGrid[i+1][j] + obstacleGrid[i][j+1];
      }

    }
  }

  return obstacleGrid[0][0];
}

int main()
{
  return 0;
}
