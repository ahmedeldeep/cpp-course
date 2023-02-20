
#include <iostream>
#include <vector>

template <class T, class F>
void operation(T first, T last, F op) {
  for (auto it = first; it != last; it++) {
    op(*it);
  }
}

int main() {
  //
  std::vector<int> numbers{10, 20, 30, 40, 50};

  operation(numbers.begin(), numbers.end(), [](int& number) { number++; });

  class increment {
   public:
    void operator()(int& number) const { number++; }
  };
  operation(numbers.begin(), numbers.end(), increment{});

  operation(numbers.begin(), numbers.end(),
            [](int number) { std::cout << number << "\n"; });
}
