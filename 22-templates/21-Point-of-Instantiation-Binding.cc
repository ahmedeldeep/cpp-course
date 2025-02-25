#include <iostream>

void bar(int x);

template <typename T>
void foo(T a) {
  bar(a);  // bar is a dependent name.
}

void bar(int x) { std::cout << "bar int" << std::endl; }

int main() {
  auto bar = [](double x) { std::cout << "bar double" << std::endl; };
  foo(10);  // bar int
}