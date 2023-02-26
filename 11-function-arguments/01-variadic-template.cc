
// Variadic Template

#include <iostream>

void my_printf(const char* string) { std::cout << string; }

template <typename T, typename... Targs>
void my_printf(const char* string, T value, Targs... Fargs) {
  for (; *string != '\0'; string++) {
    if (*string == '%' && *++string != '%') {
      std::cout << value;
      my_printf(++string, Fargs...);
      return;
    }
    std::cout << *string;
  }
}

int main() {
  //
  auto x = 7.3;
  auto y = "Hello";
  my_printf("Value of x = %d and y = %d\n", x, y);
}