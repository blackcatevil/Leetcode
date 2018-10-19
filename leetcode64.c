#include <stdlib.h>
#include <stdio.h>

#define min(x,y) (((x)<(y))? (x):(y))

int minPathSum(int** grid, int gridRowSize, int gridColSize)
{
  int row, col;

  for (row = gridRowSize-1; row >= 0; row--) {
    for (col = gridColSize-1; col >= 0; col--) {
      if (col == gridColSize-1 && row  == gridRowSize-1) {
	continue;
      } else if (col == gridColSize-1) {
	grid[row][col] += grid[row+1][col];
      } else if (row == gridRowSize-1) {
	grid[row][col] += grid[row][col+1];
      } else {
	grid[row][col] += min(grid[row][col+1], grid[row+1][col]);
      }
    }
  }

  return grid[0][0];
}

int main()
{
  return 0;
}
