
#include <cstddef>
#include <iostream>

constexpr int fun(int n) { return (n > 1) ? fun(n - 1) + fun(n - 2) : 1; }

int main() {
  //
  constexpr int x = fun(10);
  std::cout << x << "\n";
}