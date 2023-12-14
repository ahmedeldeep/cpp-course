
#include <iostream>
#include <string>
#include <vector>

struct Employee {
  std::string name;
  std::string title;
  // ...
};

struct Manager : public Employee {
  std::vector<Employee*> list;  // people managed
  int level;
  // ...
};

void fun(Manager man, Employee emp) {
  Employee* pemp{&man};  // ok
  // Manager* pman{&emp};                         // error
  Manager* pman{static_cast<Manager*>(pemp)};  // ok
}

int main() {
  //
  Employee ramy{"Ramy", "SW Engineer"};
  Employee hady{"Hady", "SW Engineer"};
  Manager fady{"Fady", "SW Manager"};

  fady.list.push_back(&ramy);
  fady.list.push_back(&hady);

  std::vector<Employee*> all{&ramy, &hady, &fady};  // ok
}
