
#include <compare>
#include <iostream>

template <typename T>
class Number {
 public:
  Number(T value) : _value{value} {}
  // auto operator<=>(const Number&) const = default;
  auto operator<=>(const Number& other) const {
    return _value <=> other._value;
  }

 private:
  T _value;
};

int main() {
  //
  std::cout << std::boolalpha << '\n';
  Number num1{2020}, num2{1010};
  // std::cout << (num1 == num2) << "\n";  // error
  std::cout << (num1 >= num2) << "\n";
  std::cout << ((num1 <=> num2) > 0) << "\n";
  //  ...
}