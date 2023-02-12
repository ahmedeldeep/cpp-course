
#include <iostream>
#include <vector>

void fun1() {
  // Reserve memory for a single element initialized to 10
  auto p1 = new int{10};

  // Reserve memory for an array of size 10
  auto p2 = new int[10];
  int p3[10]{0};

  delete p1;
  delete[] p2;
  // delete p3;  // Error, p3 is not allocated by new.
}

void fun2() {
  auto p1 = new int{10};
  std::cout << "Value of p1 is " << *p1 << "\n";

  delete p1;              // Premature deletion
  auto p2 = new int{20};  // Leaked object

  std::cout << "Value of p1 is " << *p1 << "\n";

  delete p1;  // Double deletion
}

int main() {
  //
  auto pc1 = new std::vector<int>;  // the vector is initialized to {0}
  auto pi1 = new int;               // the int is uninitialized
  // auto pii1 = new int = 10;         // Error

  auto pc2 = new std::vector<int>{};  // the vector is initialized to {00}
  auto pi2 = new int{};               // the int is initialized to 0
  auto pii2 = new int{10};            // the int is initialized to 10

  fun1();
  fun2();
}
