
// Delegating Constructors
#include <algorithm>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

class Date {
 public:
  Date(int d, int m, int y) { validate(d, m, y); }
  Date(int d, int m) { validate(d, m, 2023); }
  void print();

 private:
  int _day, _month, _year;
  void validate(int d, int m, int y) {
    if ((d > 31) || (d < 1) || (m > 12) || (m < 1) || (y > 2023) || (y < 1900))
      throw std::invalid_argument{"Date not valid"};

    _day = d;
    _month = m;
    _year = y;
  }
};

void Date::print() {
  std::cout << "Day: " << _day << "\nMonth: " << _month << "\nYear: " << _year
            << "\n";
}
int main() {
  //
  Date birthday{1, 1, 2000};
  birthday.print();
}