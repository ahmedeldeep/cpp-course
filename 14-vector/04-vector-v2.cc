// Vector Example
// Source: The C++ Programming Language (4th Edition), Bjarne Stroustrup

#include <iostream>

#include "vector-v2.h"

// vector base move constructor
template <typename T, typename A>
vector_base<T, A>::vector_base(vector_base&& other)
    : _alloc{other._alloc},
      _elem{other._elem},
      _space{other._space},
      _last{other._last} {
  other._elem = other._space = other._last = nullptr;
}

// vector base move assignment
template <typename T, typename A>
vector_base<T, A>& vector_base<T, A>::operator=(vector_base&& other) {
  if (this == &other) return *this;
  _alloc.deallocate(_elem, _last - _elem);

  _alloc = other._alloc;
  _elem = other._elem;
  _space = other._space;
  _last = other._last;
  other._elem = other._space = other._last = nullptr;

  return *this;
}

template <typename T, typename A>
void vector<T, A>::destroy_elements() {
  for (T* p = _vb._elem; p != _vb._space; ++p) p->~T();  // destroy element
  _vb._space = _vb._elem;
}

// vector constructor
template <typename T, typename A>
vector<T, A>::vector(size_type n, const T& val, const A& alloc)
    : _vb{alloc, n}  // allocate space for n elements
{
  // make n copies of val
  std::uninitialized_fill(_vb._elem, _vb._space, val);
}

// copy constructor
template <typename T, typename A>
vector<T, A>::vector(const vector<T, A>& other)
    : _vb{other._vb._alloc, other.size()} {
  std::uninitialized_copy(other._vb._elem, other._vb._space, _vb._elem);
}

// move constructor
template <typename T, typename A>
vector<T, A>::vector(vector&& other) : _vb{std::move(other._vb)} {}

// move assignment
template <typename T, typename A>
vector<T, A>& vector<T, A>::operator=(vector&& other) {
  clear();                    // destroy elements
  std::swap(_vb, other._vb);  // transfer ownership
  return *this;
}

// copy assignment
template <typename T, typename A>
vector<T, A>& vector<T, A>::operator=(const vector& other) {
  vector temp{other};      // copy allocator
  std::swap(*this, temp);  // swap representations
  return *this;            // implicitly destroy the old value
}

template <typename T, typename A>
void vector<T, A>::reserve(size_type newalloc) {
  if (newalloc <= capacity()) return;  // never decrease allocation

  vector_base<T, A> temp{_vb._alloc, size(), newalloc - size()};
  std::uninitialized_move(_vb._elem, _vb._space, temp._elem);  // move elements
  std::swap(_vb, temp);  // install new base
}  // implicitly release old space

template <typename T, typename A>
void vector<T, A>::resize(size_type newsize, const T& val) {
  reserve(newsize);
  if (size() < newsize) {  // construct new elements
    std::uninitialized_fill(_vb._space, _vb._elem + newsize, val);
  } else {
    std::destroy(_vb._elem + newsize, _vb._space);  // destroy surplus elements
  }

  _vb._space = _vb._last = _vb._elem + newsize;
}

template <class T, typename A>
void vector<T, A>::push_back(const T& val) {
  if (capacity() == size())            // no more free space; relocate:
    reserve(size() ? 2 * size() : 8);  // grow or start with 8

  std::construct_at(&_vb._elem[size()], val);  // add val at end
  ++_vb._space;                                // increment size
}

int main() {
  //
  {
    vector<int> vec1(5, 10);
    vector<int> vec2{vec1};
    vector<int> vec3{std::move(vec1)};

    vector<int> vec4(10, 20);
    vec4 = vec2;

    vector<int> vec5(15, 30);
    vec5 = std::move(vec2);

    vec5.reserve(20);
    vector<int> vec6{vec5};
    vec6.reserve(20);
    vector<int> vec7{vec5};
    vec7.reserve(20);

    vec5.resize(25);
    vec6.resize(16);
    vec7.resize(4);

    vec7.push_back(50);
    vec7.push_back(60);
  }
}
