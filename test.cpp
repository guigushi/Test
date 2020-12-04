#include "Test/test.h"

#include <iostream>

#include "ArrayTree/AbstractTree.h"
#include "ArrayTree/ArrayTree.h"
#include "ArrayTree/SegmentTree.h"
#include "ArrayTree/SimpleArray.h"
#include "ArrayTree/ZKWTree.h"
template <typename T>
class TestInstance {
  AbstractTree<T> *absTree;
  const std::vector<T> &data;

 public:
  ~TestInstance() {
    if (absTree) {
      delete (absTree);
    }
  }
  TestInstance(const std::vector<T> &v) : absTree(nullptr), data(v){};
  void build(int type) {
    if (absTree) {
      delete (absTree);
      absTree = nullptr;
    }
    switch (type) {
      case 0:
        absTree = new ArrayTree<T>(data);
        break;
      case 1:
        absTree = new ZKWTree<T>(data);
        break;
      case 2:
        absTree = new SegmentTree<T>(data);
        break;
      case 3:
        absTree = new SimpleArray<T>(data);
        break;
      default:
        break;
    }
  }
  int operator()(void) const {
    if (absTree == nullptr) {
      return -1;
    }
    int size = absTree->getSize();
    int l = test<int>::random(0, size - 2);
    int r = test<int>::random(l, size - 1);
    int v = test<int>::random(0, 10);
    absTree->update(l, r, v);
    absTree->query(l, r);
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
    std::vector<long> v(n, 0);
    for (int i = 0; i < n; ++i) {
      v[i] = test<long>::random(0, 100);
    }
    TestInstance<long> testIns(v);
    std::cout << "Testing array tree, please wait..." << std::endl;
    long arrTime = test<TestInstance<long>>(testIns).exec(cycle, 0);
    std::cout << "Array tree test finished in " << arrTime << "ms!"
              << std::endl;
    std::cout << "Testing zkw tree, please wait..." << std::endl;
    long zkwTime = test<TestInstance<long>>(testIns).exec(cycle, 1);
    std::cout << "ZKW tree test finished in " << zkwTime << "ms!" << std::endl;
    std::cout << "Testing Segment tree, please wait..." << std::endl;
    long segTime = test<TestInstance<long>>(testIns).exec(cycle, 2);
    std::cout << "Segment tree test finished in " << segTime << "ms!"
              << std::endl;
    std::cout << "Testing simple array, please wait..." << std::endl;
    long simpleTime = test<TestInstance<long>>(testIns).exec(cycle, 3);
    std::cout << "Simple array test finished in " << simpleTime << "ms!"
              << std::endl;
  }
}
