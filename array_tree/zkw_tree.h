#ifndef ZKW_TREE_H__
#define ZKW_TREE_H__
#include <vector>
template <typename T>
class zkw_tree : public abstract_tree<T> {
 private:
  std::vector<T> sum;
  std::vector<T> tag;
  int M;
  int n;

 public:
  zkw_tree(const std::vector<int>& array) {
    new (this) zkw_tree(array.size());
    for (int i = 1; i < n; i++) {
      sum[M + i] = array[i];
    }
    for (int i = M - 1; i; i--) {
      sum[i] = sum[i << 1] + sum[i << 1 | 1];
    }
  }
  zkw_tree(const int& _n) {
    n = _n;
    M = 1;
    while (M < n + 2) {
      M <<= 1;
    }
    sum.resize(M << 1, 0);
    tag.resize(M << 1, 0);
  }
  int get_size(void) { return n; }
  void update(int l, int r, T del) {
    T len = 1, lc = 0, rc = 0;
    for (l = l + M - 1, r = r + M + 1; l ^ r ^ 1; l >>= 1, r >>= 1, len <<= 1) {
      if (~l & 1) {
        tag[l + 1] += del, lc += len;
      }
      if (r & 1) {
        tag[r - 1] += del, rc += len;
      }
      sum[l >> 1] += del * lc;
      sum[r >> 1] += del * rc;
    }
    for (lc += rc, l >>= 1; l; l >>= 1) {
      sum[l] += del * lc;
    }
  }
  T query(int l, int r) {
    T res = 0, len = 1, lc = 0, rc = 0;
    for (l = l + M - 1, r = r + M + 1; l ^ r ^ 1; l >>= 1, r >>= 1, len <<= 1) {
      if (~l & 1) {
        res += sum[l + 1] + tag[l + 1] * len, lc += len;
      }
      if (r & 1) {
        res += sum[r - 1] + tag[r - 1] * len, rc += len;
      }
      res += tag[l >> 1] * lc;
      res += tag[r >> 1] * rc;
    }
    for (lc += rc, l >>= 1; l; l >>= 1) {
      res += tag[l] * lc;
    }
    return res;
  }
};
#endif