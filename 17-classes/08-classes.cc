
#include <iostream>
#include <sstream>
#include <string>

class Member {
 public:
  Member() { std::cout << "Call member class constructor" << std::endl; }
  ~Member() { std::cout << "Call member class destructor" << std::endl; }
};

class Base {
 public:
  Base() { std::cout << "Call base class constructor" << std::endl; }
  ~Base() { std::cout << "Call base class destructor" << std::endl; }
  Member member;
};

class Derived : Base {
 public:
  Derived() { std::cout << "Call derived class constructor" << std::endl; }
  ~Derived() { std::cout << "Call derived class destructor" << std::endl; }
  Member member;
};

class Nonlocal {
 public:
  // ...
  void destroy() { this->~Nonlocal(); }  // explicit destruction
 private:
  // ...
  ~Nonlocal() {}  // don’t destroy implicitly
};

void user() {
  // Nonlocal x;                  // Error
  Nonlocal* p = new Nonlocal;  // OK
  // ...
  // delete p;      // Error
  p->destroy();  // OK
}

class Shape {
 public:
  // ...
  virtual void draw() = 0;
  virtual ~Shape(){};
};

class Circle : public Shape {
 public:
  // ...
  void draw() override { std::cout << "Draw circle" << std::endl; }
  ~Circle() override { std::cout << "Remove circle" << std::endl; }
  // ...
};

void test(Shape* p) {
  p->draw();  // invoke the appropriate draw()
  // ...
  delete p;  // invoke the appropriate destructor
};

class Person {
 public:
  Person(){};  // default constructor
  Person(std::string name, int age, std::string city)
      : name(name), age(age), city(city) {
    std::cout << "Constructor called" << std::endl;
  }
  std::string name;
  int age;
  std::string city;
};

template <typename T>
class Array {
 public:
  Array(std::initializer_list<T> list) : _size(list.size()) {
    for (auto i = 0; i < list.size(); ++i) {
      _elem[i] = list.begin()[i];
    }
  }

 private:
  T* _elem;
  std::size_t _size;
};

int main() {
  { Derived x; }
  user();

  test(new Circle);

  Person s1{"Tamer", 25, "Zagazig"};  // Constructor initialization
  Person s2{s1};                      // copy initialization
  Person none{};                      // OK: default initialization
  Person no_init;                     // OK

  Array arr1{1, 2, 3, 4, 5};
  Array arr2{10, 20, 30};
}