#ifndef SIMPLE_ARRAY_H__
#define SIMPLE_ARRAY_H__
#include <vector>

#include "AbstractTree.h"
template <typename T>
class SimpleArray : public AbstractTree<T> {
  std::vector<T> data;

 public:
  SimpleArray(T n) { data.resize(n, 0); };
  SimpleArray(const std::vector<T> &nums) { data = nums; }
  void update(T i, T v) { data[i] += v; }
  T getSize(void) { return data.size(); }
  T query(T l, T r) {
    T ans = 0;
    for (T i = l; i <= r; i++) {
      ans += data[i];
    }
    return ans;
  }
  void update(T l, T r, T v) {
    for (T i = l; i <= r; i++) {
      data[i] += v;
    }
  }
};
#endif