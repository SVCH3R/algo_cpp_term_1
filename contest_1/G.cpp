#include <iostream>

void Hanoi(int n, int tow1, int tow2) {
  if (n == 1) {
    std::cout << n << ' ' << tow1 << ' ' << tow2 << std::endl;
    return;
  }
  Hanoi(n - 1, tow1, tow2);
  std::cout << n << ' ' << tow1 << ' ' << 6 - tow1 - tow2 << std::endl;
  Hanoi(n - 1, tow2, tow1);
  std::cout << n << ' ' << 6 - tow1 - tow2 << ' ' << tow2 << std::endl;
  Hanoi(n - 1, tow1, tow2);
}

int main() {
  int n;
  std::cin >> n;
  Hanoi(n, 1, 3);
}