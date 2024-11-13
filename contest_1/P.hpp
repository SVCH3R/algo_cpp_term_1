#ifndef _1P_MERGE_H_
#define _1P_MERGE_H_

template <class T, class U, class F>
void Merge(const T *begin1, const T *end1, const U *begin2, const U *end2, F *out) {
  int i = 0;
  int j = 0;
  int k = 0;
  while (i < (end1 - begin1) && j < (end2 - begin2)) {
    if (begin1[i] < begin2[j]) {
      out[k] = begin1[i];
      ++i;
    } else {
      out[k] = begin2[j];
      ++j;
    }
    ++k;
  }
  while (i < (end1 - begin1)) {
    out[k] = begin1[i];
    ++i;
    ++k;
  }
  while (j < (end2 - begin2)) {
    out[k] = begin2[j];
    ++j;
    ++k;
  }
}
#endif