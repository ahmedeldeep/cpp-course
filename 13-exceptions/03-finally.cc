
#include <iostream>

template <typename F>
struct Final {
  Final(F f) : clean{f} {}
  ~Final() { clean(); }
  F clean;
};

template <class F>
Final<F> finally(F f) {
  return Final<F>(f);
}

void test() {
  int* p = new int{7};
  auto act1 = finally([&] {
    delete p;
    std::cout << "Goodbye!\n";
  });
  {
    auto act2 = finally([] { std::cout << "finally!\n"; });
  }
}

int main() {
  //
  test();
}
