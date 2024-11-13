#include <iostream>
#include <cstring>

int main() {
  int k;
  auto line = new char[1000000];
  std::cin >> k >> line;
  int len = std::strlen(line);
  int count = 0;
  int m = 1;
  for (int i = k; i <= len; ++i) {
    if (line[i] == line[i - k]) {
      count += m;
      ++m;
    } else {
      m = 1;
    }
  }
  std::cout << count << std::endl;
  delete[] line;
  return 0;
}