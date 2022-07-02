
// Better handling of arrays with structures
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup

#include <iostream>

union dirty_stuff {
  long int i;
  long int* p;
};

int main() {
  long int x{0x10};

  dirty_stuff bad{.p = &x};
  std::cout << "bad.i = " << std::hex << bad.i << std::endl;

  dirty_stuff dangerous{.i = bad.i};
  std::cout << "*dangerous.p = " << *dangerous.p << std::endl;

  // less bad than above is to use explicit type conversion operator
  auto pointer = reinterpret_cast<long int*>(bad.i);
  std::cout << "*pointer = " << *pointer << std::endl;
}
