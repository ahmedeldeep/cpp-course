
#include <iostream>

template <typename T>
T foo(T a) {
  return bar(a);  // bar is a dependent name.
}

struct Point {
  int x, y;
};

Point bar(Point x) { return x; }

int main() {
  Point z = foo(Point{2, 3});  // point of instantiation of foo
}