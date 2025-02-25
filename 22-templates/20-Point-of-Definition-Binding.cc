#include <iostream>

void bar(double x) { std::cout << "bar double" << std::endl; };

template <typename T>
void foo(T a) {
  bar(2);
}

void bar(int x) { std::cout << "bar int" << std::endl; };

int main() {
  foo(5);  // bar double
}