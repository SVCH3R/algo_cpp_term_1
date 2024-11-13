#ifndef ARRAY_H
#define ARRAY_H
#include <stdexcept>
#include <algorithm>

class ArrayOutOfRange : public std::out_of_range {
 public:
  ArrayOutOfRange() : std::out_of_range("ArrayOutOfRange") {
  }
};

template <class T, size_t N>
class Array {
 public:
  T cstyle[N];

  T& operator[](size_t idx) {
    return cstyle[idx];
  }

  const T& operator[](size_t idx) const {
    return cstyle[idx];
  }

  T& At(size_t idx) {
    if (idx < 0 || idx >= N) {
      throw ArrayOutOfRange();
    }
    return cstyle[idx];
  }

  const T& At(size_t idx) const {
    if (idx < 0 || idx >= N) {
      throw ArrayOutOfRange();
    }
    return cstyle[idx];
  }

  T& Front() {
    return cstyle[0];
  }

  const T& Front() const {
    return cstyle[0];
  }

  T& Back() {
    return cstyle[N - 1];
  }

  const T& Back() const {
    return cstyle[N - 1];
  }

  T* Data() {
    return cstyle;
  }

  const T* Data() const {
    return cstyle;
  }

  size_t Size() const {
    return N;
  }

  bool Empty() {
    return N == 0;
  }

  bool Empty() const {
    return N == 0;
  }

  void Fill(const T& value) {
    for (size_t i = 0; i < N; ++i) {
      cstyle[i] = value;
    }
  }

  void Swap(Array<T, N>& other) {
    std::swap(cstyle, other.cstyle);
  }
};

#endif