#include <iostream>

bool IsLineHorisontal(char** array, int m, int y) {
  bool no_zeros = true;
  for (int i = 0; i < m; ++i) {
    no_zeros = no_zeros && array[y][i] == '1';
  }
  return no_zeros;
}

bool IsLineVertical(char** array, int n, int x) {
  bool no_zeros = true;
  for (int i = 0; i < n; ++i) {
    no_zeros = no_zeros && array[i][x] == '1';
  }
  return no_zeros;
}

int Counthor(char** array, int y, int x) {
  int count = 0;
  for (int i = 0; i < y; ++i) {
    if (IsLineHorisontal(array, x, i)) {
      count++;
    }
  }
  return count;
}

int Countvert(char** array, int y, int x) {
  int count = 0;
  for (int i = 0; i < x; ++i) {
    if (IsLineVertical(array, y, i)) {
      count++;
    }
  }
  return count;
}

int DistBetwHor(char** array, int y, int x) {
  int count = 0;
  int y1 = 0;
  int y2 = 0;
  bool first_line_not_checked = true;
  bool second_line_not_checked = true;
  for (int i = 0; i < y; ++i) {
    if (IsLineHorisontal(array, x, i)) {
      count++;
    }
    if (count == 1 && first_line_not_checked) {
      y1 = i;
      first_line_not_checked = false;
    }
    if (count == 2 && second_line_not_checked) {
      y2 = i;
      second_line_not_checked = false;
    }
  }
  return y2 - y1 - 1;
}

int DistBetwVert(char** array, int y, int x) {
  int count = 0;
  int x1 = 0;
  int x2 = 0;
  bool first_line_not_checked = true;
  bool second_line_not_checked = true;
  for (int i = 0; i < x; ++i) {
    if (IsLineVertical(array, y, i)) {
      count++;
    }
    if (count == 1 && first_line_not_checked) {
      x1 = i;
      first_line_not_checked = false;
    }
    if (count == 2 && second_line_not_checked) {
      x2 = i;
      second_line_not_checked = false;
    }
  }
  return x2 - x1 - 1;
}

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;

  auto** t = new char*[n];
  for (int i = 0; i < n; ++i) {
    t[i] = new char[m];
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> t[i][j];
    }
  }

  int hor = Counthor(t, n, m);
  int vert = Countvert(t, n, m);
  if (n != 1 && m != 1) {
    if ((hor == 0 && vert <= 1) || (vert == 0 && hor <= 1)) {
      std::cout << '?';
    } else {
      if (hor >= 1 && vert >= 1) {
        std::cout << "Square";
      } else {
        if (hor == 0 && vert > 1) {
          if (DistBetwVert(t, n, m) >= n) {
            std::cout << '?';
          } else {
            std::cout << "Vertical line";
          }
        } else {
          if (DistBetwHor(t, n, m) >= m) {
            std::cout << '?';
          } else {
            std::cout << "Line";
          }
        }
      }
    }
  } else {
    std::cout << '?';
  }

  for (int i = 0; i < n; ++i) {
    delete[] t[i];
  }
  delete[] t;
  return 0;
}