
#include <iostream>
#include <string>
#include <vector>

// Function Return-Type Deduction
// Generic Programming, C++14
template <typename T, typename U>
auto add(T t, U u)  // no need for the suffix return type syntax
{
  return t + u;
}

// Binary Literals & Digit Separators
auto number_hex{0x10203040};
auto number_binary{0b0001'0000'0010'0000'0011'0000'0100'0000};
auto pi{3.14159'26535'89793'23846'26433'83279'50288};

constexpr int good(int a) {
  auto sum = 0;  // OK : local variable in constexpr function
  for (int i = 0; i < a; ++i) sum += i;  // OK : loop in constexpr function
  return sum;
}

// consteval Functions
consteval int fun(int n) { return (n > 1) ? fun(n - 1) + fun(n - 2) : 1; }

void f(int n) {
  int f5 = fun(5);  // Will be evaluated at compile time
  // int fn = fun(n);  // Error: can not evaluated at compile time (n is
  // variable)
}

// Selection Statements with Initializers
void do_something(std::vector<int>& v) {
  std::vector<int> my_vec{1, 2, 3, 4, 5};

  if (auto size = my_vec.size(); size == 5) {
    for (size_t i = 0; i < size; i++) {
      my_vec[i]++;
    }
  }
}

// Initialization of an enum by a value of its underlying type
enum class Traffic_light { red, yellow, green };
enum class Warning { green, yellow, orange, red };

Warning a1{2};  // int->Warning conversion is OK

// Using Scoped enums
// std::string get_warning_text(Warning warning) {
//   switch (warning) {
//     case Warning::green: return "green";
//     case Warning::yellow: return "yellow";
//     case Warning::orange: return "orange";
//     case Warning::red: return "red";
//     default: return "nothing";
//   }
// }

std::string get_warning_text(Warning warning) {
  using enum Warning;
  switch (warning) {
    case green:
      return "green";
    case yellow:
      return "yellow";
    case orange:
      return "orange";
    case red:
      return "red";
    default:
      return "nothing";
  }
}

int main() {
  //
}