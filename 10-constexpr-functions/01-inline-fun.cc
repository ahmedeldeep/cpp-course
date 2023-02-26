
#include <cstddef>
#include <iostream>

inline int fun(int n) { return (n > 1) ? fun(n - 1) + fun(n - 2) : 1; }

int main() {
  //
  int x = fun(10);
  std::cout << x << "\n";
}