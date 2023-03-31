// Vector Example
// Source: The C++ Programming Language (4th Edition), Bjarne Stroustrup

#include "vector-v1.h"

template <class T, class A>
vector<T, A>::vector(size_type n, const T& val, const A& a) : _alloc{a} {
  _elem = _alloc.allocate(n);  // get memory for elements

  try {
    std::uninitialized_fill(_elem, _elem + n, val);  // copy elements
    _space = _last = _elem + n;

  } catch (...) {
    _alloc.deallocate(_elem, n);  // free memory
    throw;                        // rethrow
  }
}

int main() {
  //
}