

#include <iostream>

// SFINAE (Substitution Failure Is Not An Error)
struct substitution_failure {};

template <typename T>
struct substitution_succeeded : std::true_type {};

template <>
struct substitution_succeeded<substitution_failure> : std::false_type {};

template <typename T>
struct get_print_result {
 private:
  template <typename U = T>
  static auto check(U u) -> decltype(u.print());
  static substitution_failure check(...);

 public:
  using type = decltype(check(std::declval<T>()));
};

template <typename T>
struct is_printable
    : substitution_succeeded<typename get_print_result<T>::type> {};

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