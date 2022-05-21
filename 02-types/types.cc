
// Enable core guidelines checks in clang-tidy
// Using sizeof()
// Types in <cstdint> e.g. uint32_t
// std::size_t defined in <cstddef>
// Alignment, alignof(T), alignas()

#include <cstddef>
#include <cstdint>
#include <iostream>
#include <limits>

int main() {
  std::cout << "size of int = " << sizeof(int) << "\n";
  std::cout << "size of long int = " << sizeof(long int) << "\n";
  std::cout << "size of short int = " << sizeof(short int) << "\n";

  std::cout << "size of uint32_t = " << sizeof(std::uint32_t) << "\n";
  std::cout << "size of int_least8_t = " << sizeof(int_least8_t) << "\n";
  std::cout << "size of uint_fast8_t = " << sizeof(uint_fast8_t) << "\n";

  std::cout << "largest float = " << std::numeric_limits<float>::max() << "\n";
  std::cout << "minimum float = " << std::numeric_limits<float>::min() << "\n";
  std::cout << "smallest float = " << std::numeric_limits<float>::lowest()
            << "\n";
  std::cout << "char is signed = " << std::numeric_limits<char>::is_signed
            << "\n";

  std::size_t x{5};
  std::size_t y{0xF0F0F0F0};
  std::cout << "size of x = " << sizeof(x) << "\n";
  std::cout << "size of y = " << sizeof(y) << "\n";
  std::cout << "std::size_t is signed = "
            << std::numeric_limits<std::size_t>::is_signed << "\n";
  std::cout << "ssize_t is signed = " << std::numeric_limits<ssize_t>::is_signed
            << "\n";

  struct alignas(8) str {
    uint8_t x;
    uint16_t y;
    uint32_t z;
  };
  std::cout << "alignment of str = " << alignof(str) << "\n";
  std::cout << "size of str = " << sizeof(str) << "\n";
}
