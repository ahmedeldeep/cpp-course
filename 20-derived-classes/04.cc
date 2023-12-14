
#include <iostream>
#include <string>
#include <vector>

class Employee {
 public:
  enum EmployeeType { manager, employee };
  EmployeeType type;
  Employee(std::string name, std::string title)
      : type{employee}, _name{name}, _title{title} {}
  void print() const;

 private:
  std::string _name;
  std::string _title;
};

class Manager : public Employee {
 public:
  Manager(std::string name, std::string title, int level)
      : Employee(name, title), _level{level} {
    type = manager;
  }
  void add_managed(Employee* managed) { list.push_back(managed); }
  void print() const;

 private:
  std::vector<Employee*> list;  // people managed
  int _level;
};

void Employee::print() const {
  std::cout << "Name: " << _name << ", Title: " << _title << '\n';
}

void Manager::print() const {
  std::cout << "Manager: " << '\n';
  Employee::print();
  std::cout << "Managing: " << '\n';
  for (auto&& emp : list) {
    emp->print();
  }
}

void print(Employee* emp) {
  switch (emp->type) {
    case Employee::employee:
      emp->print();
      break;
    case Employee::manager: {
      const Manager* man = static_cast<const Manager*>(emp);
      man->print();
      break;
    }
    default:
      break;
  }
}

int main() {
  //
  Employee ramy{"Ramy", "SW Engineer"};
  Employee hady{"Hady", "SW Engineer"};
  Manager fady{"Fady", "SW Manager", 2};

  fady.add_managed(&ramy);
  fady.add_managed(&hady);

  print(&ramy);
  print(&fady);
}
