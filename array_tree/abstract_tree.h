#ifndef ABSTRACT_TREE_H__
#define ABSTRACT_TREE_H__
template <typename T>
class abstract_tree {
 public:
  virtual ~abstract_tree(){};
  virtual void update(int l, int r, T v) = 0;
  virtual T query(int l, int r) = 0;
  virtual int get_size(void) = 0;
};
#endif