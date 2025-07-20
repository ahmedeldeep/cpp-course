
#include <iostream>

template <typename T>
struct Pointer {
 public:
  Pointer() : _ptr(new T) {}
  ~Pointer() { delete _ptr; }
  T& operator*() { return *_ptr; }
  T* operator->() { return _ptr; }
  T* get() { return _ptr; }
  // ...

 private:
  T* _ptr;
};

struct A {
  int m = 10;
};

int main() {
  Pointer<int> p1;
  Pointer<A> p2;

  std::cout << p1.get() << std::endl;
  std::cout << p1.operator->() << std::endl;  // we don't want this

  std::cout << p2->m << std::endl;
  std::cout << p2.get()->m << std::endl;  // we don't need this
}