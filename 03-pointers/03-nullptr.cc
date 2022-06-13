
// Pointers

#include <iostream>

int main() {
  //
  int* n1;  // Not a null pointer

  // using nullptr is more readable
  int* n2 = nullptr;
  void* n3 = nullptr;

  int* n4 = 0;     // Old
  int* n5 = NULL;  // Old, taken from C

  std::cout << n1 << std::endl;
  std::cout << n2 << std::endl;
  std::cout << n4 << std::endl;
  std::cout << n5 << std::endl;

  if (n4 == nullptr) {
    std::cout << "n4 is a null pointer\n";
  }
}
