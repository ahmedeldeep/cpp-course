
#include <iostream>

// Recursive tuple definition
template <typename... Ts>
struct Tuple;

// Specialization for at least one type
template <typename T, typename... Ts>
struct Tuple<T, Ts...> : Tuple<Ts...> {
  T value;
  Tuple(const T& v, const Ts&... vs) : Tuple<Ts...>(vs...), value(v) {}
};

// Specialization for empty tuple
template <>
struct Tuple<> {
  Tuple() {}
};

// Helper to print tuple elements
void print_tuple(const Tuple<>&) {}

template <typename T, typename... Ts>
void print_tuple(const Tuple<T, Ts...>& t) {
  std::cout << t.value << " ";
  print_tuple(static_cast<const Tuple<Ts...>&>(t));
}

// Recursive get with base case handled by if constexpr
template <std::size_t N, typename T, typename... Ts>
auto& get(Tuple<T, Ts...>& t) {
  if constexpr (N == 0) {
    return t.value;
  } else {
    return get<N - 1>(static_cast<Tuple<Ts...>&>(t));
  }
}

int main() {
  Tuple<int, double, char, int> t(42, 3.14, 'x', 10);
  print_tuple(t);  // Output: 42 3.14 x 10
  std::cout << std::endl;

  std::cout << get<2>(t) << "\n";  // prints x
  return 0;
}