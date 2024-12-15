
#include <iostream>

template <typename T, std::size_t N>
class Array {
 public:
  T elem[N];
  void print() {
    for (auto i : elem) std::cout << i << '\n';
  }
};

template <std::size_t N>
using ArrayOfIntegers = Array<int, N>;

int main() {
  Array<int, 3> arr{1, 2, 3};
  arr.print();

  ArrayOfIntegers<3> arr1{1, 2, 3};
  arr1.print();
}