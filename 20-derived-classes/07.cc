
#include <iostream>
#include <string>

class Employee {
 public:
  Employee(std::string name, std::string title) : _name{name}, _title{title} {}
  std::string name() const { return _name; }
  std::string title() const { return _title; }

 private:
  std::string _name;
  std::string _title;
};

class EmployeeUpdated : public Employee {
 public:
  using Employee::Employee;  // inherit constructors
  void print() const {
    std::cout << "Name: " << name() << ", Title: " << title() << '\n';
  }
  int x;  // we forgot to provide initialization of x
};

int main() {
  //
  EmployeeUpdated ramy{"Ramy", "SW Engineer"};
  ramy.print();
}
