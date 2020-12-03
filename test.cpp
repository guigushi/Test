#include "test/test.h"

#include <iostream>

#include "array_tree/abstract_tree.h"
#include "array_tree/array_tree.h"
#include "array_tree/zkw_tree.h"
template <typename T>
class TestInstance {
  abstract_tree<T> *abs_t;
  const std::vector<T> &data;

 public:
  ~TestInstance() {
    if (abs_t) {
      delete (abs_t);
    }
  }
  TestInstance(const std::vector<T> &v): abs_t(nullptr), data(v) { };
  void build(int type){
    if(abs_t){
      delete(abs_t);
      abs_t = nullptr;
    }
    switch(type){
      case 0:
      abs_t = new array_tree<T>(data);
      break;
      default:
      abs_t = new zkw_tree<T>(data);
      break;
    }
  }
  int operator()(void) const {
    if(abs_t == nullptr){
      return -1;
    }
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
    TestInstance<int> testIns(v);
    std::cout<<"Testing array tree, please wait..."<<std::endl;
    long arr_time = test<TestInstance<int>>(testIns).exec(cycle, 0);
    std::cout << "Array tree test finished in " << arr_time <<"ms!"<< std::endl;
    std::cout << "Test zkw tree, please wait..."<<std::endl;
    long zkw_time = test<TestInstance<int>>(testIns).exec(cycle, 1);
    std::cout << "ZKW tree test finished in " << zkw_time << "ms!" << std::endl;
  }
}
