
// Ellipsis

#include <cstdarg> /* va_list, va_start, va_arg, va_end */
#include <iostream>

void my_printf(const char* string, ...) {
  va_list ap;
  va_start(ap, string);

  for (; *string != '\0'; string++) {
    if (*string == '%') {
      switch (*++string) {
        case '%':  // ignore
          break;
        case 'd':  // double
          std::cout << va_arg(ap, double);
          break;
        case 's':  // string
          std::cout << va_arg(ap, const char*);
          break;
        default:
          break;
      }
      ++string;
    }
    std::cout << *string;
  }
  va_end(ap);
}

int main() {
  //
  auto x = 7.3;
  auto y = "Hello";
  my_printf("Value of x = %d and y = %s\n", x, y);
}