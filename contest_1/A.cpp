#include <iostream>

int Neib(int **a, int x, int y) {
  return a[x][y - 1] + a[x][y + 1] + a[x - 1][y] + a[x - 1][y - 1] + a[x - 1][y + 1] + a[x + 1][y] + a[x + 1][y - 1] +
         a[x + 1][y + 1];
}

int main() {
  int n;
  int t;
  std::cin >> n >> t;
  // array and its copy
  auto field = new int *[n + 2];
  for (int i = 0; i < n + 2; ++i) {
    field[i] = new int[n + 2];
  }
  auto newfield = new int *[n + 2];
  for (int i = 0; i < n + 2; ++i) {
    newfield[i] = new int[n + 2];
  }
  for (int i = 0; i < n + 2; ++i) {
    for (int j = 0; j < n + 2; ++j) {
      field[i][j] = 0;
    }
  }
  // array input
  for (int i = 1; i < n + 1; ++i) {
    for (int j = 1; j < n + 1; ++j) {
      std::cin >> field[i][j];
    }
  }

  for (int i = 0; i < n + 2; ++i) {
    for (int j = 0; j < n + 2; ++j) {
      newfield[i][j] = 0;
    }
  }

  // main code
  if (n == 1) {
    std::cout << 0;
    return 0;
  }
  for (int k = 0; k < t; ++k) {
    for (int i = 1; i < n + 1; ++i) {
      for (int j = 1; j < n + 1; ++j) {
        if (field[i][j] == 0 && Neib(field, i, j) == 3) {
          newfield[i][j] = 1;
        }
        if (field[i][j] == 1 && (Neib(field, i, j) < 2 || Neib(field, i, j) > 3)) {
          newfield[i][j] = 0;
        }
        if (field[i][j] == 1 && (Neib(field, i, j) == 2 || Neib(field, i, j) == 3)) {
          newfield[i][j] = 1;
        }
      }
    }
    for (int i = 1; i < n + 1; ++i) {
      for (int j = 1; j < n + 1; ++j) {
        field[i][j] = newfield[i][j];
      }
    }
  }
  for (int i = 1; i < n + 1; ++i) {
    for (int j = 1; j < n + 1; ++j) {
      std::cout << field[i][j] << ' ';
    }
    std::cout << std::endl;
  }
  for (int i = 0; i < n + 2; ++i) {
    delete[] field[i];
    delete[] newfield[i];
  }
  delete[] field;
  delete[] newfield;
}