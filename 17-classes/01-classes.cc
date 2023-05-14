
#include <iostream>
#include <string>

class Person {
 public:
  Person(std::string name, int age) : _name(name), _age(age) {}
  void print() {  //
    std::cout << "Name: " << _name << ", Age: " << _age << "\n";
  };

 private:
  std::string _name;
  int _age;
};

class Date {
  int d, m, y;

 public:
  // ...
  Date(int, int, int);  // day, month, year
  Date(int, int);       // day, month, today’s year
  Date(int);            // day, today’s month and year
  Date();               // default Date: today
  Date(const char*);    // date in string representation
};

int main() {
  //
  Person someone{"Ramy", 25};
  someone.print();
}