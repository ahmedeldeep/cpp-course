
#include <iostream>
#include <vector>

template <typename T>
using Value_type = typename T::value_type;

template <typename T>
Value_type<T> sum(T& con) {
  Value_type<T> sum{};
  for (auto& item : con) sum += item;
  return sum;
}

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  std::cout << sum(vec) << std::endl;
  return 0;
}