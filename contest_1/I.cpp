#include <cmath>
#include <iostream>

bool Sets(int64_t c, int64_t w, int64_t h, int64_t n) {
  return c / h * (c / w) >= n;
}

int64_t Binsearch(int64_t w, int64_t h, int64_t n, int64_t left, int64_t right) {
  int64_t m;
  while (left < right - 1) {
    m = left + (right - left) / 2;
    if (Sets(m, w, h, n)) {
      right = m;
    } else {
      left = m;
    }
  }
  if (Sets(left, w, h, n)) {
    return left;
  }
  return right;
}

int main() {
  int64_t w, h, n;
  std::cin >> w >> h >> n;
  int64_t left = 1;
  int64_t right = n * std::max(w, h) + 1;
  std::cout << Binsearch(w, h, n, left, right);
  //
}