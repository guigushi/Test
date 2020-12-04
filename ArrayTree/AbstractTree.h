#ifndef AbstractTree_H__
#define AbstractTree_H__
template <typename T>
class AbstractTree {
 public:
  virtual ~AbstractTree(){};
  virtual void update(T l, T r, T v) = 0;
  virtual T query(T l, T r) = 0;
  virtual T getSize(void) = 0;
};
#endif