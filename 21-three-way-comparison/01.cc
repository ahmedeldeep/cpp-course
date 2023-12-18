
#include <cstring>
#include <iostream>

int compare(const char* a, const char* b) {
  //  A negative return value means less-than,
  // 0 means equal,
  // and a positive value means greater-than.
  return std::strcmp(a, b);
}

int main() {
  std::cout << compare("B", "A") << "\n";
  std::cout << compare("A", "A") << "\n";
  std::cout << compare("A", "B") << "\n";
}