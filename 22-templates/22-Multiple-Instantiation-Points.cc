#include <iostream>

namespace NS {
struct Point {
  int x, y;
};

int fun(Point p, int x) {
  std::cout << "fun int called" << std::endl;
  return x;
}
}  // namespace NS

template <typename T>
double foo(T t, double d) {
  return fun(t, d);  // fun might be bound to NS::fun(Point,int)
}

// may bind fun to NS::fun(Point,int), narrowing 1.1 to 1
const auto X1 = foo(NS::Point{}, 1.1);

namespace NS {
double fun(Point p, double x) {
  std::cout << "fun double called" << std::endl;
  return x;
}
}  // namespace NS

// binds to NS::fun(Point,double); the best match
const auto X2 = foo(NS::Point{}, 2.2);

int main() {}

// fun double called
// fun double called