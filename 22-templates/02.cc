

#include <iostream>

template <typename T, std::size_t N>
class array {
 public:
  T elem[N];
  void print();
};

template <typename T, std::size_t N>
void array<T, N>::print() {
  for (auto i : elem) std::cout << i << '\n';
}

template<typename T>
struct Shape {
  static const int hight = 10; // ok
  //static int width = 20; // error: not const
  static int depth;
};

// template<typename T> 
// int Shape<T>::hight = 30; // error: redefinition

int main() {
  array<int, 3> arr{1, 2, 3};
  arr.print();
}