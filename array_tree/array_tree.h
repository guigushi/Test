//
/// this file is a data structure
/// uses the array tree to realize
/// modify and query randomly in
/// the complexity of log N
//
#ifndef ARRAY_TREE_H__
#define ARRAY_TREE_H__
#include <vector>

#include "abstract_tree.h"
template <typename T>  // T can be int, long and so on
class array_tree : public abstract_tree<T> {
  int n;
  std::vector<T> df;
  std::vector<T> mf;
  int lowbit(int x) { return (-x) & x; }
  int ask(int x) {
    T res = 0;
    for (int i = x + 1; i > 0; i -= lowbit(i)) {
      res += df[i] * (x + 2) - mf[i];
    }
    return res;
  }
  void add(int x, T v) {
    for (int i = x + 1; i <= n; i += lowbit(i)) {
      df[i] += v;
      mf[i] += v * (x + 1);
    }
  }

 public:
  array_tree(int _n) {
    n = _n + 1;
    df.resize(n, 0);
    mf.resize(n, 0);
  }
  array_tree(const std::vector<T>& v) {
    new (this) array_tree(v.size());
    if (v.size() > 0) {
      add(0, v[0]);
      for (int i = 1; i < n - 1; i++) {
        add(i, v[i] - v[i - 1]);
      }
    }
  }
  int get_size(void) { return n - 1; }
  void update(int l, int r, T v) {
    add(l, v);
    add(r + 1, -v);
  }
  void update(int x, T v) { update(x, x, v); }
  T query(int l, int r) { return ask(l) - ask(r - 1); }
  T query(int x) { return query(x, x); }
};
#endif
