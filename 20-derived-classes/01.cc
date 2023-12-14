
#include <iostream>
#include <string>
#include <vector>

struct Employee {
  std::string name;
  std::string title;
  // ...
};

struct Manager {
  Employee employee;
  std::vector<Employee*> list;  // people managed
  int level;
  // ...
};

int main() {
  //
  Employee ramy{"Ramy", "SW Engineer"};
  Employee hady{"Hady", "SW Engineer"};
  Manager fady{"Fady", "SW Manager"};

  fady.list.push_back(&ramy);
  fady.list.push_back(&hady);

  std::vector<Employee*> all{&ramy, &hady, &fady};  // error
}