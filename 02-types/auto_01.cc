
// Using auto for automatic type deduction

#include <iostream>

typedef unsigned int* Pint32_t;  // old
using Pint32_t = unsigned int*;  // C++ Type Alias

int main() {
  int a1{123};
  char a2 = 123;

  auto a3 = 123;  // the type of a3 is int
  // auto a4;        // error: declaration of 'auto a4' has no initializer
  auto a5{123};

  std::cout << "a3 type is " << typeid(a3).name() << std::endl;
  std::cout << "a5 type is " << typeid(a5).name() << std::endl;

  auto x1 = {1, 2};  // x1 type is std::initializer_list<int>
  int x2 = {3};      // x2 type is is std::initializer_list<int>

  // auto x3 = {1, 2.0};  // error: cannot deduce element type
  // auto x4{1, 2};       // error: not a single element

  auto x5{3};

  std::cout << "x1 type is " << typeid(x1).name() << std::endl;
  std::cout << "x2 type is " << typeid(x2).name() << std::endl;
  std::cout << "x5 type is " << typeid(x5).name() << std::endl;
}
