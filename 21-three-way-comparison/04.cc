
#include <compare>
#include <iostream>

class Person {
 public:
  auto operator<=>(const Person& other) const {
    if (is_equivalent(other)) return std::partial_ordering::equivalent;
    if (is_parent_of(other)) return std::partial_ordering::greater;
    if (other.is_parent_of(*this)) return std::partial_ordering::less;
    return std::partial_ordering::unordered;
  }
  void parent(Person* p) { _parent = p; }
  void son(Person* p) { _son = p; }
  void daughter(Person* p) { _daughter = p; }

 private:
  Person* _parent{nullptr};
  Person* _son{nullptr};
  Person* _daughter{nullptr};

  bool is_equivalent(const Person& other) const {
    if (this == &other) return true;  // same person
    if (_parent == other._parent) return true;
    return false;
  }
  bool is_parent_of(const Person& other) const {
    if (this == other._parent) return true;
    return false;
  }
};

int main() {
  //
  Person father, son, daughter, other;
  son.parent(&father);
  daughter.parent(&father);
  father.son(&son);
  father.daughter(&daughter);

  if (father > son) {  // or (father <=> son) > 0
    std::cout << "father is greater than son"
              << "\n";
  }
  if (son < father) {  // (son <=> father) < 0
    std::cout << "son is less than father"
              << "\n";
  }
  if (std::is_eq(son <=> daughter)) {  // or (son <=> daughter) == 0
    std::cout << "son is equivalent to daughter"
              << "\n";
  }
  if (std::is_eq(other <=> daughter)) {
    std::cout << "other is no related to daughter"
              << "\n";
  }
}