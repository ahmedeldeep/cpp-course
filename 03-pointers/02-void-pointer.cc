
// void* Example
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup

int main() {
  int* pi;
  void* pv = pi;  // ok: implicit conversion of int* to void*

  // error: ISO C++ does not allow
  // indirection on operand of type 'void *'
  *pv;

  // error: expression must be a pointer
  // to a complete object type
  ++pv;

  int* pi2 = static_cast<int*>(pv);  // explicit conversion back to int*

  double* pd1 = pv;                        // error
  double* pd2 = pi;                        // error
  double* pd3 = static_cast<double*>(pv);  // unsafe
}
