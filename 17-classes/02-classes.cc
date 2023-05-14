
#include <iostream>

class Account {
 public:
  explicit Account(const char* name, int balance = 0)
      : _name(name), _balance(balance) {}
  const char* name() { return _name; }
  int balance() { return _balance; }

 private:
  const char* _name;
  int _balance;
};

void print(Account acc) {
  std::cout << "Name: " << acc.name() << ", Balance: " << acc.balance() << "\n";
}

class Date {
  int d{today.d};
  int m{today.m};
  int y{today.y};

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
  Account a1{"Hany"};            // OK: considered explicit
  Account a2 = Account{"Hany"};  // OK: explicit
  Account a3 = {"Hany"};         // error
  Account a4 = "Hany";           // error

  print("Fady");           // error
  print({"Fady"});         // error
  print(Account{"Fady"});  // OK: explicit
}