// Vector Example
// Source: The C++ Programming Language (4th Edition), Bjarne Stroustrup

#include "vector-v1.h"

// warning: naive implementation
template <class T, class A>
vector<T, A>::vector(size_type n, const T& val, const A& a) : _alloc{a} {
  _elem = _alloc.allocate(n);  // get memory for elements - may throw
  _space = _last = _elem + n;

  for (T* p = _elem; p != _last; ++p)
    a.construct(p, val);  // construct copy of val in *p - may throw
}

int main() {
  //
}