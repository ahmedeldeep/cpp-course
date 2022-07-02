
// Better handling of arrays with structures
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup

#include <iostream>

enum Type { str, num };
struct Entry {
  char const* name;
  Type t;
  char const* s;  // use s if t==str
  int i;          // use i if t==num
};

void print_entry(Entry& p) {
  std::cout << p.name << " = ";

  if (p.t == str) {
    std::cout << p.s << "\n";
  } else {
    std::cout << p.i << "\n";
  }
}

int main() {
  Entry entry1{.name = "Car Manufacturer", .t = str, .s = "BMW"};
  Entry entry2{.name = "Person Height", .t = num, .i = 185};

  print_entry(entry1);
  print_entry(entry2);
}
