
// Default Arguments

#include <string>

// class user {
//  public:
//   user(std::string name) : _name(name), _age(0) {}
//   user(std::string name, int age) : _name(name), _age(age) {}

//  private:
//   std::string _name;
//   int _age;
// };

// class user {
//  public:
//   user(std::string name) : user(name, 0) {}
//   user(std::string name, int age) : _name(name), _age(age) {}

//  private:
//   std::string _name;
//   int _age;
// };

class user {
 public:
  user(std::string name, int age = {}) : _name(name), _age(age) {}

 private:
  std::string _name;
  int _age;
};

int var = 5;
void fun1(int x, int y = var);  // OK
// void fun1(int x, int y = var, int z);  // ERROR: default only for trailing
// args
void fun1(int x = 0, int y) {}  // OK: default for y supplied in the same scope
// void fun1(int x = 5, int y);    // ERROR: redefinition of default argument

void fun2() {
  var = 10;
  fun1();  // fun1(0, 10)
}

int main() {
  //
  user user_1{"Ahmed"};
  user user_2{"Tamer", 30};
}