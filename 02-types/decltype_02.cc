
// Using decltype is helpful in generic programming

#include <iostream>

// Generic Programming
template <typename T, typename U>
auto add(T t, U u) -> decltype(t + u)  // suffix return type syntax
{
  return t + u;
}

int main() {
  auto result1{add(5, 4.5)};
  std::cout << "result1 type is " << typeid(result1).name() << std::endl;

  auto result2{add(5, 5)};
  std::cout << "result2 type is " << typeid(result2).name() << std::endl;
}
