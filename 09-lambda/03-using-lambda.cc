
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

int main() {
  //
  std::vector<int> numbers{10, 20, 30, 40, 50};

  int max = 0;
  int min = std::numeric_limits<int>::max();
  int sum = 0;

  auto minmaxsum = [&max, &min, sum](int number) mutable -> int {
    sum += number;
    if (number > max) max = number;
    if (number < min) min = number;
    std::cout << sum << "\n";
    return sum;
  };

  std::for_each(numbers.begin(), numbers.end(), minmaxsum);

  std::cout << "Min = " << min << " Max = " << max << " Sum = " << sum << "\n";
}
