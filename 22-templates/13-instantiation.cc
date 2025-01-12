
#include <iostream>

template <typename T>
class List {
 public:
  void sort() { op.sort(); }
  void print() { op.print(); }

 private:
  T op;
};

class Sorter {
 public:
  void sort() {  //
    std::cout << "Sorting...\n";
  }
};

class Printer {
 public:
  void print() {  //
    std::cout << "Printing...\n";
  }
};

// Explicit instantiation
// template class List<Sorter>;
// error: no member named 'print' in 'Sorter'

int main() {
  List<Sorter> ls;
  List<Printer> lp;

  ls.sort();
  lp.print();
}