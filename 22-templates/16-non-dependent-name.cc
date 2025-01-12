
#include <iostream>

struct Point {
  int x, y;
};

Point bar(Point x) { return x; }

template <typename T>
T foo(T a) {
  return bar(Point{2, 3});  // bar is not a dependent name.
}

int main() {
  Point z = foo(Point{2, 3});  // point of instantiation of foo
}