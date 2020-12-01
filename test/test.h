#include <sys/timeb.h>
#include <time.h>

#include <functional>
#include <random>
#include <vector>
template <class T>
class test {
  T *func;
  long init_time;

 public:
  test(T *_func) {
    timeb tb;
    ftime(&tb);
    init_time = tb.time;
    func = _func;
  }
  static int random(int l, int r) {
    std::default_random_engine gen;
    std::uniform_int_distribution<int> dist(l, r);
    return dist(gen);
  }
  long get_time(void) {
    timeb tb;
    ftime(&tb);
    return (tb.time - init_time) * 1000 + (tb.millitm);
  }
  long exec(int cycle) {
    long begin_time = get_time();
    for (int i = 0; i < cycle; i++) {
      if ((*func)() < 0) {
        return -1;
      }
    }
    return get_time() - begin_time;
  }
};