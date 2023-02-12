

// Manager object example.
// TODO: implement the remaining constructors according to the rule of five.

#include <cstddef>
#include <iostream>

template <typename T, std::size_t N>
class Array {
 public:
  T* _data = new T[N];

  ~Array() {  // non-default destructor
    std::cout << "Destructor called" << std::endl;
    delete[] _data;
  };
  void* operator new(std::size_t, void* p) { return p; };
};

void f(int n) {
  int* p = new (std::nothrow) int[n];  // allocate n ints on the free store
  if (p == nullptr) {                  // no memory available
    // ... handle allocation error ...
  }
  // ...
  operator delete(p, std::nothrow);  // deallocate *p
}

int main() {
  //
  Array<int, 3> myArray;

  auto p2 = new int[10];
  auto p3 = new (p2) int;  // placement new
}