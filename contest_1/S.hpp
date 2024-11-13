#ifndef S_HEAP_H
#define S_HEAP_H

int Parent(int index) {
  return (index - 1) / 2;
}
int Left(int index) {
  return 2 * index + 1;
}
int Right(int index) {
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
void PushHeap(T* begin, T* end) {
  int index = end - 1 - begin;
  while (Parent(index) > 0) {
    if (*(begin + Parent(index)) < *(begin + index)) {
      Swap(*(begin + index), *(begin + Parent(index)));
      index = Parent(index);
    } else {
      return;
    }
  }
  if (index < 3) {
    if (*(begin) < *(begin + index)) {
      Swap(*(begin), *(begin + index));
    }
  }
  return;
}
template <class T>
void PopHeap(T* begin, T* end) {
  Swap(*(begin), *(end - 1));
  int index = 0;
  while (Left(index) < end - begin - 1) {
    if (Right(index) > end - begin - 2) {
      if (*(begin + index) < *(begin + Left(index))) {
        Swap(*(begin + index), *(begin + Left(index)));
        return;
      }
      return;
    }
    if (*(begin + Left(index)) < *(begin + Right(index))) {
      if ((*(begin + index)) < (*(begin + Right(index)))) {
        Swap(*(begin + index), *(begin + Right(index)));
        index = Right(index);
      } else {
        break;
      }
    } else {
      if ((*(begin + index)) < (*(begin + Left(index)))) {
        Swap(*(begin + index), *(begin + Left(index)));
        index = Left(index);
      } else {
        break;
      }
    }
  }
  return;
}
#endif