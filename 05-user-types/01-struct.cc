
// Structures
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup

#include <iostream>

struct Address {
  const char* name;
  int number;
  const char* street;
  const char* town;
  char state[2];
  const char* zip;
};

void print_addr(Address* p) {
  std::cout << p->name << '\n'
            << p->number << ' ' << p->street << '\n'
            << p->town << '\n'
            << p->state[0] << p->state[1] << ' ' << p->zip << '\n';
}

void print_addr2(const Address& r) {
  std::cout << r.name << '\n'
            << r.number << ' ' << r.street << '\n'
            << r.town << '\n'
            << r.state[0] << r.state[1] << ' ' << r.zip << '\n';
}

int main() {
  Address jd;
  jd.name = "Jim Dandy";
  jd.number = 61;

  Address jd2 = {"Jim Dandy",      61,         "South St",
                 "New Providence", {'N', 'J'}, "07974"};

  Address jd3 = {.name = "Jim Dandy",
                 .number = 61,
                 .street = "South St",
                 .town = "New Providence",
                 .state = {'N', 'J'},
                 .zip = "07974"};

  print_addr2(jd2);
}