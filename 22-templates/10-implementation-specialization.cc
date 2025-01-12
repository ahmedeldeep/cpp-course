
#include <iostream>

template <typename T, std::size_t N>  // Primary Template
struct Point;

template <typename T>
struct Point<T, 1> {
  T x;
};

template <typename T>
struct Point<T, 2> {
  T x, y;
};

template <typename T>
struct Point<T, 3> {
  T x, y, z;
};

int main() {
  //
  Point<int, 3> myPoint{10};
  // Point<int, 0> myPoint{10}; // error
  // Point<int, 4> myPoint{10}; // error

  return 0;
}