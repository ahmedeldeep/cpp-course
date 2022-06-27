
// Structures
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup

#include <iostream>
#include <string>

struct Address {
 public:
  Address(const std::string n, int nu, const std::string& s,
          const std::string& t, const std::string& st)
      : _name(n), _number(nu), _street(s), _town(t), _state(st){};
  void print() const;

 private:
  std::string _name;
  int _number;
  std::string _street;
  std::string _town;
  std::string _state;
};

void Address::print() const {
  std::cout << _name << '\n'
            << _number << ' ' << _street << '\n'
            << _town << '\n'
            << _state << '\n';
}

int main() {
  Address jd{"Jim Dandy", 61, "South St", "New Providence", "NJ"};
  jd.print();
}