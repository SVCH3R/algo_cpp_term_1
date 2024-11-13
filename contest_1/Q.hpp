#ifndef _1P_MERGESORT_H_
#define _1P_MERGESORT_H_

template <class T>
void Merge(T arr[], int size) {
  int i = 0;
  int mid = size / 2;
  int j = mid;
  int k = 0;
  auto out = new T[size];
  while (i < mid && j < size) {
    if (arr[i] < arr[j]) {
      out[k] = arr[i];
      ++i;
    } else {
      out[k] = arr[j];
      ++j;
    }
    ++k;
  }
  while (i < (mid)) {
    out[k] = arr[i];
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
}

template <class M>
void Sort(M *begin, M *end) {
  if (!(1 < end - begin)) {
    return;
  }
  M *m = begin + (end - begin) / 2;
  Sort(begin, m);
  Sort(m, end);
  Merge(begin, end - begin);
}

#endif