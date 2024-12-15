#include <iostream>

template <typename T>
class Point {
 public:
  Point(T x, T y) : _x(x), _y(y) {}

 private:
  T _x, _y;
};

int main() {
  Point p1{1, 2};
  Point p2{1.1, 2.2};
}