
// Type Traits

#include <cstddef>  // for std::size_t
#include <iostream>

template <typename T, std::size_t N>
class Array {
 public:
  // Default constructor
  Array() = default;

  // Variadic template constructor
  template <typename... Args>
  Array(Args... args) : _data{args...} {}
  T& operator[](std::size_t idx) { return _data[idx]; }

 private:
  T _data[N];
};

template <typename T>
struct array_traits;

// Specialization for Array
template <typename T, std::size_t N>
struct array_traits<Array<T, N>> {
  using value_type = T;
  static constexpr std::size_t size = N;
};

template <typename Array>
void find(Array arr, typename array_traits<Array>::value_type val) {
  for (auto idx = 0; idx < array_traits<Array>::size; idx++) {
    if (arr[idx] == val) {
      std::cout << "Found at index: " << idx << std::endl;
      return;
    }
  }
}

int main() {
  Array<int, 4> myArr{1, 2, 3, 4};
  find(myArr, 3);  // Found at index: 2
}