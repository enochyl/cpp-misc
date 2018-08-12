#include <iostream>
#include <stdio.h>

#define N 10

void printSolution(int board[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      printf(" %d ", board[i][j]);
    printf("\n");
  }
}


bool isSafe(int board[N][N], int row, int col) {
  int i, j;
  // Check the row on the left
  for (i = 0; i < col; i++)
    if (board[row][i])
      return false;
  // Check upper diagonal on the left
  for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    if (board[i][j])
      return false;
  // Check lower diagonal on the left
  for (i = row, j = col; i < N && j >= 0; i++, j--)
    if (board[i][j])
      return false;
  return true;
}


bool solveNQUtil (int board [N][N], int col) {
  // Base case: if all queens are placed
  if (col >= N)
    return true;
  // Consider this column and try placing the queen in all rows one by one
  for (int i = 0; i < N; i++) {
    if (isSafe(board, i, col)) {
      board[i][col] = 1;
      // Place the rest of the queens recursively
      if (solveNQUtil(board, col+1))
        return true;
      // If placing queen at board[i][col] is not valid
      board[i][col] = 0;
    }
  }
  return false;
}

bool solveNQ() {
  int board[N][N] = {
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
  };
  if (solveNQUtil(board, 0) == false) {
    printf("Solution does not exist\n");
    return false;
  }
  printSolution(board);
  return true;
}


int main() {
  solveNQ();
  return 0;
}
