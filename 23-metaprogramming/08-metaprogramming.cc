
#include <iostream>

struct A {
  int m = 10;
  void print() { std::cout << m << std::endl; }
};

struct B {
  int m = 20;
};

template <typename T>
void printer(T something_printable) {
  something_printable.print();
}

int main() {
  A myA;
  printer(myA);

  B myB;
  // printer(myB); // error
  return 0;
}