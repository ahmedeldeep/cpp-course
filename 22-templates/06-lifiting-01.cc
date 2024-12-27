
#include <iostream>

int add(int num1, int num2) { return num1 + num2; }
int multiply(int num1, int num2) { return num1 * num2; }

template <typename T>
T add(T num1, T num2) {
  return num1 + num2;
}

template <typename T>
T multiply(T num1, T num2) {
  return num1 * num2;
}

template <typename T, typename Operation>
T calculate(T num1, T num2, Operation operation) {
  return operation(num1, num2);
}

int main() {
  //
  std::cout << calculate(2, 3, add<int>) << std::endl;
}