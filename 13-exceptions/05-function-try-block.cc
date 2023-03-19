
#include <iostream>
#include <vector>

class MyVector {
 public:
  MyVector(int size) try : _vec(size) {
  } catch (std::exception&) {
    std::cerr << "exception from MyVector\n";
  }  // implicit "throw;"

 private:
  std::vector<int> _vec;
};

void test() try {
  //
  std::vector<int> vec(-10);
} catch (std::length_error&) {
  std::cerr << "length error\n";
}

int main() {
  test();
  try {
    MyVector vec{-10};
  } catch (std::exception&) {
    std::cerr << "exception caught from MyVector\n";
  }
}