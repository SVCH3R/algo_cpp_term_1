#include <iostream>

void Solve(int n, bool rev) {
  if (n == 1 && !rev) {
    std::cout << 1 << ' ';
    return;
  }
  if (n == 1 && rev) {
    std::cout << -1 << ' ';
    return;
  }
  if (n == 2 && !rev) {
    std::cout << 1 << ' ' << 2 << ' ';
    return;
  }
  if (n == 2 && rev) {
    std::cout << -2 << ' ' << -1 << ' ';
    return;
  }
  if (!rev) {
    Solve(n - 1, false);
    Solve(n - 2, true);
    std::cout << n << ' ';
    Solve(n - 2, false);
  } else {
    Solve(n - 2, true);
    std::cout << -n << ' ';
    Solve(n - 2, false);
    Solve(n - 1, true);
  }
}

int main() {
  int n;
  std::cin >> n;
  Solve(n, false);
}