// Vector Example
// Source: The C++ Programming Language (4th Edition), Bjarne Stroustrup

#include <iterator>

#include "vector-v1.h"

template <class T, class A>
vector<T, A>::vector(size_type n, const T& val, const A& a) : _alloc{a} {
  _elem = _alloc.allocate(n);  // get memory for elements

  std::iterator p = _elem;

  try {
    std::iterator end = _elem + n;
    for (; p != end; ++p) _alloc.construct(p, val);  // construct
    _last = _space = p;

  } catch (...) {
    for (std::iterator q = _elem; q != p; ++q)
      _alloc.destroy(q);  // destroy constructed elements

    _alloc.deallocate(_elem, n);  // free memory
    throw;                        // rethrow
  }
}

template <class For, class T>
void uninitialized_fill(For beg, For end, const T& x) {
  For p;
  try {
    for (p = beg; p != end; ++p)
      ::new (static_cast<void*>(&*p)) T(x);  // construct copy of x in *p
  } catch (...) {
    for (For q = beg; q != p; ++q) (&*q)->~T();  // destroy element
    throw;                                       // rethrow
  }
}

int main() {
  //
}