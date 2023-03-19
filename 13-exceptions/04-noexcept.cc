
#include <iostream>
#include <vector>

void test() noexcept {
  //
  std::vector<int> vec(-10);
}

void try_test() {
  try {
    test();
  } catch (std::length_error&) {
    std::cerr << "length error \n";
  }
}

int main() {
  //
  try_test();
}