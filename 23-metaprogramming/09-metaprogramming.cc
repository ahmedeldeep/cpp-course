
#include <iostream>

// SFINAE (Substitution Failure Is Not An Error)
template <typename T>
std::false_type detect_is_printable(...);

template <typename T>
std::true_type detect_is_printable(decltype(std::declval<T>().print())*);

template <typename T>
struct is_printable : decltype(detect_is_printable<T>(nullptr)) {};

struct printer {
  template <typename U>
  typename std::enable_if<is_printable<U>::value>::type print(U& printable) {
    printable.print();
  }

  template <typename U>
  typename std::enable_if<!is_printable<U>::value>::type print(
      U& non_printable) {
    std::cout << "Object does not have a print function" << std::endl;
  }
};

struct A {
  int m = 10;
  void print() { std::cout << m << std::endl; }
};

struct B {
  int m = 20;
};

int main() {
  A myA;
  printer p;
  p.print(myA);

  B myB;
  p.print(myB);

  std::cout << is_printable<A>::value << std::endl;
  std::cout << is_printable<B>::value << std::endl;
  return 0;
}