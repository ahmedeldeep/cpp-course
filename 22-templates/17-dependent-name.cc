

#include <iostream>
#include <vector>

template <typename T>
auto sum(T& con) -> typename T::value_type {
  typename T::value_type sum{};
  for (auto& item : con) sum += item;
  return sum;
}

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  std::cout << sum(vec) << std::endl;
  return 0;
}