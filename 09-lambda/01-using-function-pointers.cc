
#include <iostream>
#include <vector>

template <class T>
void increment(T& number) {
  number++;
}

template <class T>
void print(T& number) {
  std::cout << number << "\n";
}

template <class Iter, class T>
void operation(Iter first, Iter last, void (*op)(T&)) {
  for (auto it = first; it != last; it++) {
    op(*it);
  }
}

int main() {
  //
  std::vector<int> numbers{10, 20, 30, 40, 50};
  operation(numbers.begin(), numbers.end(), &increment<int>);
  operation(numbers.begin(), numbers.end(), &print<int>);
}
