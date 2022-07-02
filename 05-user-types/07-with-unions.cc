
// Better handling of arrays with structures
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup

#include <iostream>

union Status {
  unsigned int reg;
  struct {
    unsigned int TXE : 1;   // Transmit data register empty
    unsigned int TC : 1;    // Transmission complete
    unsigned int RXNE : 1;  // Read data register not empty
    unsigned int ERR : 3;   // Error
    unsigned int : 26;      // Reserved
  } bitfields;
};

enum Type { str, num };
struct Entry {
  char const* name;
  Type t;
  union {
    char const* s;
    int i;
  } value;
};

void print_entry(Entry& p) {
  std::cout << p.name << " = ";

  if (p.t == str) {
    std::cout << p.value.s << "\n";
  } else {
    std::cout << p.value.i << "\n";
  }
}

int main() {
  Entry entry1{.name = "Car Manufacturer", .t = str, .value = {.s = "BMW"}};
  Entry entry2{.name = "Person Height", .t = num, .value = {.i = 185}};

  print_entry(entry1);
  print_entry(entry2);
}
