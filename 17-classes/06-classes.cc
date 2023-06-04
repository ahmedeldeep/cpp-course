
#include <iostream>
#include <string>

class Person {
 public:
  Person() {}
  Person& name(std::string name) {
    _name = name;
    return *this;
  }
  Person& lives_in(std::string city) {
    _city = city;
    return *this;
  }
  Person& works_at(std::string company) {
    _company = company;
    return *this;
  }
  Person& as(std::string position) {
    _position = position;
    return *this;
  }

  void print() const {
    std::cout << "Name: " << _name << "\n";
    std::cout << "City: " << _city << "\n";
    std::cout << "Company: " << _company << "\n";
    std::cout << "Position: " << _position << "\n";
  }

 private:
  std::string _name, _city, _company, _position;
};

int main() {
  //
  Person p1;
  p1.name("Rady").lives_in("Cairo").works_at("SoftTec").as("SW Dev.").print();
}