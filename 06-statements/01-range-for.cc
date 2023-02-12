
// Range For Loop
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup

#include <cstddef>
#include <iostream>
#include <vector>

struct point {
  int x, y;
};

std::ostream& operator<<(std::ostream& os, const point& p) {
  std::cout << "{" << p.x << "," << p.y << "}";
  return os;
}

template <typename T, std::size_t N>
struct array {
  T elem[N];

  T* begin() noexcept { return (T*)elem; }
  const T* begin() const noexcept { return (T*)elem; }

  T* end() noexcept { return &elem[N]; }
  const T* end() const noexcept { return &elem[N]; }

  constexpr std::size_t size() const noexcept { return N; }

  T& operator[](std::size_t n) { return elem[n]; }
  const T& operator[](std::size_t n) const { return elem[n]; }

  void print() const {
    for (int i = 0; i != size(); ++i) std::cout << elem[i] << '\n';
  }

  void print_it() const {
    for (auto it = begin(); it != end(); ++it) std::cout << *it << '\n';
  }

  void print_range() const {
    for (auto&& entry : *this) std::cout << entry << '\n';
  }
};

int main() {
  //
  array<point, 3> arr{point{1, 2}, point{3, 4}, point{5, 6}};
  // arr.print();
  // arr.print_it();
  arr.print_range();

  int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  for (auto x : v) std::cout << x << '\n';
  for (auto x : {10, 21, 32, 43, 54, 65}) ++x;

  for (size_t i = 0; i < 10; i++) std::cout << v[i] << '\n';
}