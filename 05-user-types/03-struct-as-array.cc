
// Structures

#include <iostream>
#include <string>

constexpr size_t buffer_size = 14;

struct Data {
  char buffer[buffer_size];
};

int main() {
  Data output;
  strcpy(output.buffer, "Welcome to C++");

  char input_buffer[buffer_size];
  input_buffer = output.buffer;  // error: array type 'char [10]'
                                 // is not assignable

  Data input = output;  // OK
  std::cout << input.buffer << "\n";
}