
// Swap example using rvalue reference & std::move

#include <iostream>
#include <string>
#include <utility>
#include <vector>

template <class T>
void swap_old(T& a, T& b) {
  auto tmp{a};
  a = b;
  b = tmp;
}

template <class T>
void swap_modern(T& a, T& b) {
  auto tmp{static_cast<T&&>(a)};
  a = static_cast<T&&>(b);
  b = static_cast<T&&>(tmp);
}

template <class T>
void swap_modern_move(T& a, T& b) {
  auto tmp{std::move(a)};
  a = std::move(b);
  b = std::move(tmp);
}

int main() {
  //
  std::vector<std::string> vect_str_1{"this is the first string"};
  std::vector<std::string> vect_str_2{"this is the second string"};

  std::cout << "before swap; vect_str_1 addr = " << vect_str_1.data()
            << " & vect_str_2 addr = " << vect_str_2.data() << std::endl;

  swap_modern_move(vect_str_1, vect_str_2);

  std::cout << "after swap; vect_str_1 addr = " << vect_str_1.data()
            << " & vect_str_2 addr = " << vect_str_2.data() << std::endl;

  std::cout << "\nvect_str_1 data = " << vect_str_1[0] << std::endl;
  std::cout << "vect_str_2 data = " << vect_str_2[0] << std::endl;
}
