
#include <iostream>

struct Point {
  int x, y;
};

auto add(Point a, Point b) { return Point{a.x + b.x, a.y + b.y}; }

int main() {
  //
  auto p3{add({1, 2}, {5, 6})};
  std::cout << "X = " << p3.x << ", Y = " << p3.y << std::endl;
}