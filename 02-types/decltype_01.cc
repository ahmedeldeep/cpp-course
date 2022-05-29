
// decltype example

#include <iostream>

struct Str {
  double a;
  int b;
};

int main() {
  decltype(Str::a) x{0};
  decltype(Str::b) y{0};

  std::cout << "x type is " << typeid(x).name() << std::endl;
  std::cout << "y type is " << typeid(y).name() << std::endl;
}
