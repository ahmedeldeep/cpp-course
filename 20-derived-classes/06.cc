
#include <iostream>

class Base {
 public:
  virtual void fun1();
  virtual void fun2();
};

void Base::fun1() { std::cout << "Base fun1\n"; }
void Base::fun2() { std::cout << "Base fun2\n"; }

class Derived : public Base {
 public:
  void fun2() override;
};

void Derived::fun2() { std::cout << "Derived fun2\n"; }

void call(Base& b) {
  b.fun1();
  b.fun2();
}

int main() {
  //
  Derived d;
  call(d);
}
