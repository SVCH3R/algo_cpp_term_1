#include <iostream>

void Set(int **board, int n, int i, int j) {
  for (int x = 0; x < n; x++) {
    board[x][j]++;
    board[i][x]++;
    if (0 <= i + j - x && i + j - x < n) {
      board[i + j - x][x]++;
    }
    if (0 <= i - j + x && i - j + x < n) {
      board[i - j + x][x]++;
    }
  }
  board[i][j]--;
}

void Rem(int **board, int n, int i, int j) {
  for (int x = 0; x < n; x++) {
    board[x][j]--;
    board[i][x]--;
    if (0 <= i + j - x && i + j - x < n) {
      board[i + j - x][x] -= 1;
    }
    if (0 <= i - j + x && i - j + x < n) {
      board[i - j + x][x] -= 1;
    }
  }
  board[i][j]++;
}

int Solve(int **board, int n, int i) {
  int count = 0;
  for (int j = 0; j < n; j++) {
    if (board[i][j] == 0) {
      Set(board, n, i, j);
      if (i == n - 1) {
        count++;
      } else {
        count += Solve(board, n, i + 1);
      }
      Rem(board, n, i, j);
    }
  }
  return count;
}

int main() {
  int n;
  std::cin >> n;
  auto board = new int *[n];
  for (int i = 0; i < n; ++i) {
    board[i] = new int[n];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      board[i][j] = 0;
    }
  }
  std::cout << Solve(board, n, 0);
  for (int i = 0; i < n; ++i) {
    delete[] board[i];
  }
  delete[] board;
  return 0;
}