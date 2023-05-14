
#include <iostream>

class Account {
 public:
  explicit Account(const char* name, int balance = 0)
      : _name(name), _balance(balance) {}
  const char* name() { return _name; }
  int balance() { return _balance; }
  void print() const;

 private:
  const char* _name;
  int _balance;
};

void Account::print() const {
  std::cout << "Name: " << _name << ", Balance: " << _balance << "\n";
}

int main() {
  //
  const Account a1{"Shady", 10};
  a1.print();
}