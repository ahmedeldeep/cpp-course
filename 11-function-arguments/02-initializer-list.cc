
// Initializer List

#include <initializer_list>
#include <iostream>

void my_printf(const char* string) { std::cout << string; }

template <class T>
void my_printf(const char* string, std::initializer_list<T> args) {
  auto it = args.begin();
  for (; *string != '\0'; string++) {
    if (*string == '%' && *++string != '%') {
      std::cout << *(it++);
      ++string;
    }
    std::cout << *string;
  }
}

int main() {
  //
  auto x = 7.3;
  auto y = 5.6;
  my_printf("Value of x = %d and y = %d\n", {x, y});
}