
// Better handling of arrays with structures
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup

#include <cstddef>
#include <iostream>

struct point {
  int x, y;
};

std::ostream& operator<<(std::ostream& os, point& p) {
  std::cout << "{" << p.x << "," << p.y << "}";
  return os;
}

template <typename T, std::size_t N>
struct array {
  T elem[N];

  T* begin() noexcept { return elem; }
  const T* begin() const noexcept { return elem; }

  T* end() noexcept { return elem + N; }
  const T* end() const noexcept { return elem + N; }

  constexpr std::size_t size() const noexcept { return N; }

  T& operator[](std::size_t n) { return elem[n]; }
  const T& operator[](std::size_t n) const { return elem[n]; }

  void print() {
    for (int i = 0; i != size(); ++i) std::cout << elem[i] << '\n';
  }
};

int main() {
  //
  array<point, 3> arr{point{1, 2}, point{3, 4}, point{5, 6}};
  arr.print();
}