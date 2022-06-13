
// Pointers
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup

int multiply(int* x, int* y) { return *x * *y; };

int main() {
  int a1{10};
  int* a2{&a1};  // pointer to a1.
  int a3{*a2};   // getting int value a2 points to.

  int** a4;     // pointer to pointer
  int* a5[10];  // pointer to an array with 10 ints.

  // pointer to function multiply
  int (*f1)(int*, int*){multiply};
}
