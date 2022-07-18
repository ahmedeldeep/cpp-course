
// Enumerations
// Reference: The C++ Programming Language (4th Edition), Bjarne Stroustrup

#include <iostream>

enum class Traffic_light { red, yellow, green };
enum class Warning { green, yellow, orange, red };

// Warning a1 = 7;                     // error : no int->Warning conversion
// int a2 = green;                     // error: green not in scope
// int a3 = Warning::green;            // error : no Warning->int conversion
// Warning a4 = Traffic_light::green;  // error : different types
// Warning a5 = Warning::green;        // OK

// enum class Warning : int { green, yellow, orange, red };
// enum class Warning : char { green, yellow, orange, red };

void print_warning_enum() {
  std::cout << static_cast<int>(Warning::green) << std::endl;
  std::cout << static_cast<int>(Warning::yellow) << std::endl;
  std::cout << static_cast<int>(Warning::orange) << std::endl;
  std::cout << static_cast<int>(Warning::red) << std::endl;
}

int main() {
  //
  print_warning_enum();
}