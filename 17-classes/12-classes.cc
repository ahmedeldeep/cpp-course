
#include <iostream>
#include <string>

class Person {
 public:
  Person(std::string name, std::string city, std::string company,
         std::string position)
      : _name(name), _city(city), _company(company), _position(position) {}
  Person() = default;
  ~Person() = default;
  Person(const Person&) = default;
  Person(Person&&) = default;
  Person& operator=(const Person&) = default;
  Person& operator=(Person&&) = default;

  void print() const {
    std::cout << "Name:     " << _name << "\n";
    std::cout << "City:     " << _city << "\n";
    std::cout << "Company:  " << _company << "\n";
    std::cout << "Position: " << _position << "\n";
  }

 private:
  std::string _name, _city, _company, _position;
};

int main() {
  //
  Person p1{"Rady", "Zagazig", "SoftTec", "SW Dev."};
  Person p2 = p1;
  p2.print();
  Person p3;
}