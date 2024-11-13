#include <iostream>

int main() {
  auto* testline = new char[10000];
  std::cin.getline(testline, 10000);
  int n = 0;
  while (testline[n] != '#') {
    n++;
  }
  auto* line = new char[n];
  for (int i = 0; i < n; ++i) {
    line[i] = testline[i];
  }
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      std::cout << line[i];
    }
  }
  for (int i = n - 1; i > 0; --i) {
    if (i % 2 != 0) {
      std::cout << line[i];
    }
  }
  delete[] line;
  delete[] testline;
}