
// Using auto is helpful with hard to find out types

#include <iostream>
#include <vector>

template <class T>
void f1(std::vector<T>& arg) {
  for (typename std::vector<T>::iterator p = arg.begin(); p != arg.end(); ++p)
    *p = 7;
}

template <class T>
void f2(std::vector<T>& arg) {
  for (auto p = arg.begin(); p != arg.end(); ++p) *p = 7;
}

int main() {
  //
}
