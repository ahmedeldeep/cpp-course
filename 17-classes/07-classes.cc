
#include <iostream>
#include <string>

class Date {
 public:
  Date(int dd = 0, int mm = 0, int yy = 0);
  static void set_default(int dd, int mm, int yy);
  void print() const;

 private:
  int d, m, y;
  static Date default_date;
};

void Date::set_default(int dd, int mm, int yy) {
  default_date = {dd, mm, yy};
  // ... check that the Date is valid ...
}

Date::Date(int dd, int mm, int yy) {
  d = dd ? dd : default_date.d;
  m = mm ? mm : default_date.m;
  y = yy ? yy : default_date.y;
  // ... check that the Date is valid ...
}

void Date::print() const {
  std::cout << "Date: " << d << "." << m << "." << y << "\n";
}

Date Date::default_date{1, 1, 1970};

template <typename T>
class Tree {
 private:
  using value_type = T;               // member alias
  enum Policy { rb, splay, treeps };  // member enum
  class Node {                        // member class
   public:
    void f(Tree*);

   private:
    Node* right;
    Node* left;
    value_type value;
  };
  Node* top;

 public:
  void g(Node*);
};

template <typename T>
void Tree<T>::Node::f(Tree* p) {
  // top = right;                 // Error
  p->top = right;              // OK
  value_type v = left->value;  // OK
}

template <typename T>
void Tree<T>::g(Tree::Node* p) {
  // value_type val = right->value;   // Error : no object of type
  value_type v = p->right->value;  // Error : Node::right is private
  p->f(this);                      // OK
}

int main() {
  //
  Date d1;
  d1.print();                  // Date: 1.1.1970
  d1.set_default(2, 2, 1980);  // or Date::set_default
  Date d2;
  d2.print();  // Date: 2.2.1980
}