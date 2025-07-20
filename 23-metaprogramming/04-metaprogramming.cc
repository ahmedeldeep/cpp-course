
#include <iostream>

template <unsigned N, typename... Cases>  // general case; never instantiated
struct selection;

template <unsigned N, typename T, typename... Cases>
struct selection<N, T, Cases...>
    : selection<N - 1, Cases...> {  // recursive inheritance
};

template <typename T, typename... Cases>  // final case: N==0
struct selection<0, T, Cases...> {
  using type = T;
};

template <unsigned N, typename... Cases>
using Select = typename selection<N, Cases...>::type;

template <auto Val>
struct type_of {
  constexpr static auto value = Val;
};

int main() {
  const int x = 5;
  const int y = 10;

  using result = Select<(x < y), type_of<x - y>, type_of<y - x>>;
  std::cout << result::value << std::endl;  // Output: 5
}