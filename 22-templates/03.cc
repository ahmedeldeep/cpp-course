
#include <iostream>

template <typename T>
struct Shape {
  static const int hight = 10;
  static const int width = 20;
  virtual void print() = 0;  // ok

  // template <typename U>
  // virtual void combine(U&) = 0;  // error: virtual on member function
  // templates
};

int main() {}