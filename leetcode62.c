#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int uniquePaths(int m, int n)
{
  int row, col, ans;
  int **grid = malloc(sizeof(int*)*m);

  for (int i = 0; i < m; i++) {
    grid[i] = malloc(sizeof(int)*n);
    memset(grid[i], 0, sizeof(int)*n);
  }

  grid[m-1][n-1] = 1;
  for (row = m-1; row >= 0; row--) {
    for (col = n-1; col >= 0; col--) {
      if (col == n-1 && row  == m-1) {
	continue;
      } else if (col == n-1) {
	grid[row][col] += grid[row+1][col];
      } else if (row == m-1) {
	grid[row][col] += grid[row][col+1];
      } else {
	grid[row][col] = grid[row][col] + grid[row][col+1] + grid[row+1][col];
      }
    }
  }

  ans = grid[0][0];
  for (int i = 0; i < m; i++)
    free(grid[i]);
  free(grid);

  return ans;
}

int main()
{
  return 0;
}
