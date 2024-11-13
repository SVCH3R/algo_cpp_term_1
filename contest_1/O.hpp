#ifndef _1O_TEMPLATES_H_
#define _1O_TEMPLATES_H_

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

template <class T, class U>
T* LowerBound(T* begin, T* end, U& x) {
  T* l = begin - 1;
  T* r = end;
  while (l < r - 1) {
    T* m = l + (r - l) / 2;
    if (*m < x) {
      l = m;
    } else {
      r = m;
    }
  }
  return r;
}

template <class T, class U>
T* UpperBound(T* begin, T* end, U& x) {
  T* l = begin - 1;
  T* r = end;
  while (l < r - 1) {
    T* m = l + (r - l) / 2;
    if (x < *m) {
      r = m;
    } else {
      l = m;
    }
  }
  return l + 1;
}

#endif