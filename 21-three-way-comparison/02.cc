

#include <iostream>

template <typename T>
class Number {
 public:
  Number(T value) : _value{value} {}
  bool operator==(const Number&) const = default;

 private:
  T _value;
};

int main() {
  //
  std::cout << std::boolalpha << '\n';
  Number num1{2020}, num2{1010};
  std::cout << (num1 == num2) << "\n";
  std::cout << (num1 != num2) << "\n";
}