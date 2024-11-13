#include <iostream>

template <class T>
void Swap(T& first, T& second) {
  T cont = first;
  first = second;
  second = cont;
}

template <class T>
T* Partition(T* begin, T* end) {
  T* pivot_point = begin;
  T pivot_value = *begin;
  for (int i = 0; i < end - begin; ++i) {
    if (begin[i] < pivot_value) {
      ++pivot_point;
      Swap(begin[i], *pivot_point);
    }
  }
  Swap(*begin, *pivot_point);
  return pivot_point;
}

void QuickSort(int* begin, int* end) {
  if (begin >= end) {
    return;
  }
  int* pivot = Partition(begin, end);
  QuickSort(begin, pivot);
  QuickSort(pivot + 1, end);
}

template <class T, class U>
bool BinarySearch(T* begin, T* end, U& x) {
  T* l = begin - 1;
  T* r = end;
  while (l < r - 1) {
    T* m = l + (r - l) / 2;
    if (!(*m < x) && !(x < *m)) {
      return true;
    }
    if (*m < x) {
      l = m;
    } else {
      r = m;
    }
  }
  return false;
}

int main() {
  int n, m, b;
  bool f = true;
  std::cin >> n;
  auto a = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  QuickSort(a, a + n);
  std::cin >> m;
  for (int i = 0; i < m; ++i) {
    std::cin >> b;
    if (f) {
      f *= BinarySearch(a, a + n, b);
    }
  }
  if (f) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
  delete[] a;
}