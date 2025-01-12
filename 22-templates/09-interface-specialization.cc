
#include <iostream>

template <typename T>
class Point {
 public:
  Point(const T& x, const T& y) : _x(x), _y(y) {}

 private:
  const T &_x, _y;
};

template <>
class Point<float> {
 public:
  Point(const float x, const float y) : _x(x), _y(y) {}

 private:
  const float _x, _y;
};

int main() {
  //
}