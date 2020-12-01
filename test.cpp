#include "test/test.h"

#include <iostream>

#include "array_tree/abstract_tree.h"
#include "array_tree/array_tree.h"
#include "array_tree/zkw_tree.h"
template <typename T>
class TestInstance {
  abstract_tree<T> *abs_t;

 public:
  ~TestInstance() {
    if (abs_t) {
      delete (abs_t);
    }
  }
  TestInstance(abstract_tree<T> *ins) { abs_t = ins; }
  int operator()(void) const {
    int size = abs_t->get_size();
    for (int i = 0; i < 1000; i++) {
      int l = test<int>::random(0, size - 2);
      int r = test<int>::random(l, size - 1);
      int v = test<int>::random(-1000, 1000);
      abs_t->update(l, r, v);
      abs_t->query(l, r);
    }
    return 0;
  }
};
int main() {
  int n = 0, cycle = 0;
  while (1) {
    std::cout << "******************************************" << std::endl;
    std::cout << "Please enter size:" << std::endl;
    std::cin >> n;
    std::cout << "Please enter cycle:" << std::endl;
    std::cin >> cycle;
    if (n < 0 || cycle < 0) {
      std::cout << "Error input, program terminated!" << std::endl;
      return 0;
    }
    std::vector<int> v(n, 0);
    for (int i = 0; i < n; ++i) {
      v[i] = test<int>::random(0, 100000);
    }
    TestInstance<int> arr_test(new array_tree<int>(v));
    TestInstance<int> zkw_test(new zkw_tree<int>(v));
    std::cout << "Data generated, Begin test!" << std::endl;
    long arr_time = test<TestInstance<int>>(&arr_test).exec(cycle);
    std::cout << "Test array tree: time = " << arr_time << std::endl;
    long zkw_time = test<TestInstance<int>>(&zkw_test).exec(cycle);
    std::cout << "Test zkw tree: time = " << zkw_time << std::endl;
  }
}
