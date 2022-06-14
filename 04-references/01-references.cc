
// References
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup

#include <iostream>

void increment(int &aa) { ++aa; }
void f() {
  int x = 1;
  increment(x);  // x=2
}

int var = 20;
int &fun1() { return var; }

int main() {
  //
  int x{10};
  int &x1{x};  // ok: x1 is a lvalue reference
  ++x1;

  int &x2;      // error: 'x2' declared as reference but not initialize
  int &x3{20};  // error: cannot bind non-const lvalue reference of type 'int&'
                // to an rvalue of type

  const double &cdr{1};  // OK

  fun1() = 10;
}
