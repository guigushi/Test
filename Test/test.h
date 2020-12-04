#include <sys/timeb.h>
#include <time.h>

#include <cstdlib>
#include <functional>
#include <random>
#include <vector>
template <class T>
class test {
  T func;
  long init_time;

 public:
  test(const T& _func) : func(_func) {
    timeb tb;
    ftime(&tb);
    init_time = tb.time;
  }
  static int random(int l, int r) {
    // std::default_random_engine gen;
    // std::uniform_int_distribution<int> dist(l, r);
    return rand() % (r - l) + l;  // dist(gen);
  }
  long get_time(void) {
    timeb tb;
    ftime(&tb);
    return (tb.time - init_time) * 1000 + (tb.millitm);
  }
  long exec(int cycle, int type) {
    long begin_time = get_time();
    func.build(type);
    for (int i = 0; i < cycle; i++) {
      if ((func)() < 0) {
        return -1;
      }
    }
    return get_time() - begin_time;
  }
};