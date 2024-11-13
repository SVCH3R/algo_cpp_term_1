#include <iostream>

template <class T>
int64_t Merge(T arr[], int size) {
  int64_t cnt = 0;
  int i = 0;
  int mid = size / 2;
  int j = mid;
  int k = 0;
  auto out = new T[size];
  while (i < mid && j < size) {
    if (arr[i] <= arr[j]) {
      out[k] = arr[i];
      cnt += (j - mid);
      ++i;
    } else {
      out[k] = arr[j];
      ++j;
    }
    ++k;
  }
  while (i < (mid)) {
    out[k] = arr[i];
    cnt += (j - mid);
    ++i;
    ++k;
  }
  while (j < size) {
    out[k] = arr[j];
    ++j;
    ++k;
  }
  for (int i = 0; i < size; ++i) {
    arr[i] = out[i];
  }

  delete[] out;
  return cnt;
}

template <class M>
int64_t Sort(M *begin, M *end) {
  if (!(1 < end - begin)) {
    return 0;
  }
  int *m = begin + (end - begin) / 2;

  return Sort(begin, m) + Sort(m, end) + Merge(begin, end - begin);
}

int main() {
  int n;
  std::cin >> n;
  auto *a = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::cout << Sort(a, a + n);
  delete[] a;
  return 0;
}