
#include <iostream>

template <typename T, std::size_t N>
class Array {
 public:
  template <typename... E>  // variadic template
  Array(E... elem) : elem{elem...} {}
  T& operator[](int i) { return elem[i]; }
  // ...

 private:
  T elem[N];
};

template <std::size_t N>
class Array<void*, N> {  // complete specialization
 public:
  template <typename... E>
  Array(E... elem) : elem{elem...} {}
  void*& operator[](int i) { return elem[i]; }
  // ...

 private:
  void* elem[N];
};

template <typename T, std::size_t N>
class Array<T*, N> : private Array<void*, N> {  // partial specialization
 public:
  using Base = Array<void*, N>;
  template <typename... E>
  Array(E... elem) : Base(elem...) {}
  T*& operator[](int i) { return reinterpret_cast<T*&>(Base::operator[](i)); }
  // ...
};

int main() {
  //
  Array<int, 5> iArray{1, 2, 3, 4, 5};
  Array<int*, 5> piArray;
  Array<char*, 5> pcArray;
  Array<double*, 5> pdArray;

  int x = 1, y = 2, z = 3;
  Array<int*, 3> myArray{&x, &y, &z};

  myArray[0] = &y;
  std::cout << *myArray[0] << std::endl;
}