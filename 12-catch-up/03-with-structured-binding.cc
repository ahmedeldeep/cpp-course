
#include <iostream>
#include <vector>

struct Point {
  int x, y;
};

auto add(Point a, Point b) { return Point{a.x + b.x, a.y + b.y}; }

auto increment(std::vector<Point>& points) {
  for (auto& [x, y] : points) {
    x++;
    y++;
  }
}

int main() {
  //
  auto [p3_x, p3_y]{add({1, 2}, {5, 6})};
  std::cout << "X = " << p3_x << ", Y = " << p3_y << std::endl;

  std::vector<Point> points{{1, 2}, {5, 6}};
  std::cout << "X = " << points[0].x << ", Y = " << points[0].y << std::endl;
  increment(points);
  std::cout << "X = " << points[0].x << ", Y = " << points[0].y << std::endl;
}