#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isValidSudoku(char** board, int boardRowSize, int boardColSize)
{
  int row[9];
  int col[9];
  int* tmp;
  char index;

  for (int i = 0; i < boardRowSize; i++) {
    memset(row, 0, sizeof(int)*9);
    memset(col, 0, sizeof(int)*9);
    for (int j = 0; j < boardColSize; j++) {
      index = board[i][j];
      if (index != '.') {
        tmp = &col[(index-'0')-1];
        if (*tmp != 0)
	  return false;
        (*tmp)++;
      }
      
      index = board[j][i];
      if (index != '.') {
        tmp = &row[(index-'0')-1];
        if (*tmp != 0)
	  return false;
        (*tmp)++;
      }
    }
  }

  for (int k = 0; k < 9; k++) {
    memset(row, 0, sizeof(int)*9);
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
	index = board[i+(k/3)*3][j+(k%3)*3];
	if (index == '.')
	  continue;
        tmp = &row[(index-'0')-1]; 
	if (*tmp != 0)
	  return false;

	(*tmp)++;
      }
    }
  }

  return true;
}

int main()
{
  return 0;
}
