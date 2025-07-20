
#include <iostream>

template <bool B, typename T = void>
struct enable_if {};

template <typename T>
struct enable_if<true, T> {
  using type = T;
};

template <typename T>
struct Pointer {
 public:
  Pointer() : _ptr(new T) {}
  ~Pointer() { delete _ptr; }
  T& operator*() { return *_ptr; }

  // Use SFINAE to enable operator-> only for class types
  template <typename U = T>
  typename enable_if<std::is_class<U>::value, U*>::type operator->() {
    return _ptr;
  }

  // Provide a way to access the pointer for non-class types
  template <typename U = T>
  typename enable_if<!std::is_class<U>::value, U*>::type get() {
    return _ptr;
  }

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
  std::cout << p2->m << std::endl;
  // std::cout <<p2.get()->m<< std::endl; // now gives an error
  // std::cout <<p1.operator->()<< std::endl; // now gives an error
}