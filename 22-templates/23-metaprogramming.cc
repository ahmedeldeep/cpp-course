
#include <iostream>
#include <type_traits>

struct A {
  int m;
};

struct B {
  virtual void foo();
};

// Normal function
int subtract(int x, int y) {
  if (x > y) {
    return x - y;
  } else {
    return y - x;
  }
}

template <auto Val>  // C++17
struct type_of {
  constexpr static auto value = Val;
};

template <typename Cond, typename Then, typename Else>
struct conditional {};

template <typename Then, typename Else>
struct conditional<type_of<true>, Then, Else> {
  using type = Then;
};

template <typename Then, typename Else>
struct conditional<type_of<false>, Then, Else> {
  using type = Else;
};

int main() {
  if (!std::is_polymorphic<A>::value)
    std::cout << "Type A is not a polymorphic type.\n";

  if (std::is_polymorphic<B>::value)
    std::cout << "Type B is a polymorphic type.\n";

  const int x = 5;
  const int y = 10;

  using result =
      conditional<type_of<(x > y)>, type_of<x - y>, type_of<y - x>>::type;
  std::cout << result::value << std::endl;
}