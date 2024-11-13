#include <algorithm>
#include <cstring>
#include <iostream>

struct Student {
  int sum;
  char name[42];
  char surname[42];
};

int main() {
  int n;
  std::cin >> n;
  Student f[1000000];
  int curr = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> f[i].surname;
    std::cin >> f[i].name;
    std::cin >> curr;
    f[i].sum = curr;
    std::cin >> curr;
    f[i].sum += curr;
    std::cin >> curr;
    f[i].sum += curr;
  }

  std::stable_sort(f, f + n, [](Student s1, Student s2) { return s1.sum > s2.sum; });

  for (int i = 0; i < n; ++i) {
    std::cout << f[i].surname << ' ' << f[i].name << std::endl;
  }
}