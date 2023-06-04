
// Slicing

#include <iostream>

struct Base {
  int b;
  Base() {}
  Base(const Base&) {
    std::cout << "Call base class copy constructor" << std::endl;
  }
  // ...
};

struct Derived : Base {
  int d;
  Derived() {}
  Derived(const Derived&) {
    std::cout << "Call member derived copy destructor" << std::endl;
  }
  // ...
};

void naive(Base* p) {
  Base b2 = *p;  // slice
  // ...
}

int main() {
  Derived d;
  naive(&d);
  Base bb = d;  // slice
  // ...
}
