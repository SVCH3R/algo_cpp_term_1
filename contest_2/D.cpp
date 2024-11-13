#ifndef _HEAP_H
#define _HEAP_H

int Parent(int index) {
  return (index - 1) / 2;
}
int LeftChild(int index) {
  return 2 * index + 1;
}
int RightChild(int index) {
  return 2 * index + 2;
}

template <class T>
void Swap(T& a, T& b) {
  T c = a;
  a = b;
  b = c;
  return;
}

template <class T>
void SiftDown(T* a, int i, int size) {
  if (size == 1) {
    return;
  }
  int left = LeftChild(i);
  int right = RightChild(i);
  int largest = i;
  if (left < size && a[largest] < a[left]) {
    largest = left;
  }
  if (right < size && a[largest] < a[right]) {
    largest = right;
  }
  if (largest != i) {
    Swap(a[i], a[largest]);
    SiftDown(a, largest, size);
  }
  return;
}

template <class T>
void MakeHeap(T* begin, T* end) {
  int size = end - begin;
  if (size == 1) {
    return;
  }
  for (int i = (size - 1) / 2; i >= 0; --i) {
    SiftDown(begin, i, size);
  }
}

template <class T>
void SortHeap(T* begin, T* end) {
  int size = end - begin;
  if (size == 1) {
    return;
  }
  MakeHeap(begin, end);
  for (int i = size - 1; i > 0; --i) {
    Swap(begin[0], begin[i]);
    --size;
    SiftDown(begin, 0, size);
  }
}

#endif