
#include <climits>
#include <iostream>

template <typename T>
T max_value();

template <>
constexpr int max_value<int>() {
  return INT_MAX;
}
template <>
constexpr char max_value<char>() {
  return CHAR_MAX;
}

int main() {
  //
  std::cout << max_value<int>() << std::endl;
}