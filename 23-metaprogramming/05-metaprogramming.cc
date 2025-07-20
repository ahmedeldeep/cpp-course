
#include <iostream>
#include <type_traits>

template <typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type foo(T t) {
  std::cout << "Integral type: " << t << std::endl;
}

int main() {
  foo(42);  // OK: prints "Integral type: 42"
  // foo(3.14);  // Error: not enabled for double
}
