#ifndef _1R_KTH_H_
#define _1R_KTH_H_

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

template <class T>
void KthElement(T* begin, T* k, T* end) {
  T* partition = Partition(begin, end);

  if (!(partition < k || k < partition)) {
    return;
  }
  if (partition < k) {
    KthElement(partition + 1, k, end);
    return;
  }
  if (k < partition) {
    KthElement(begin, k, partition);
    return;
  }
}
#endif