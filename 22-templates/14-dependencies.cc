
#include <iostream>
#include <vector>

bool print;
template <typename T>
T sum(std::vector<T>& vec) {
  T sum{0};
  for (auto& item : vec) {
    sum += item;
  }

  if (print) {
    std::cout << "sum = " << sum << std::endl;
  }

  return sum;
}

int main() {
  std::vector<int> myVec{1, 2, 3};
  print = true;
  sum(myVec);
}