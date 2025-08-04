
// SI Units Example
// This example demonstrates how to use C++ templates and constexpr to create a
// type-safe unit system.
// References: The C++ Programming Language 4/E by Bjarne Stroustrup,
// Section 28.7

#include <iostream>
#include <string>
#include <string_view>
#include <type_traits>

// Unit definition
template <int M, int K, int S>
struct Unit {
  static constexpr int m = M, kg = K, s = S;
};

// Unit aliases
using M = Unit<1, 0, 0>;
using Kg = Unit<0, 1, 0>;
using S = Unit<0, 0, 1>;

// Unit arithmetic
template <typename U1, typename U2>
using Unit_plus = Unit<U1::m + U2::m, U1::kg + U2::kg, U1::s + U2::s>;

template <typename U1, typename U2>
using Unit_minus = Unit<U1::m - U2::m, U1::kg - U2::kg, U1::s - U2::s>;

// Unit aliases for derived units
using MpS = Unit_minus<M, S>;     // M/s -> Unit<1, 0, -1>
using MpS2 = Unit_minus<MpS, S>;  // M/s^2 -> Unit<1, 0, -2>

// Quantity
template <typename U>
struct Quantity {
  long double val;
  constexpr explicit Quantity(long double d) : val{d} {}
  constexpr Quantity() : val{0.0} {}
};

// Arithmetic operators
// Addition operator
template <typename U>
constexpr Quantity<U> operator+(Quantity<U> x, Quantity<U> y) {
  return Quantity<U>{x.val + y.val};
}

// Subtraction operator
template <typename U>
constexpr Quantity<U> operator-(Quantity<U> x, Quantity<U> y) {
  return Quantity<U>{x.val - y.val};
}

// Multiplication operator
template <typename U1, typename U2>
constexpr Quantity<Unit_plus<U1, U2>> operator*(Quantity<U1> x,
                                                Quantity<U2> y) {
  return Quantity<Unit_plus<U1, U2>>{x.val * y.val};
}

// Division operator
template <typename U1, typename U2>
constexpr Quantity<Unit_minus<U1, U2>> operator/(Quantity<U1> x,
                                                 Quantity<U2> y) {
  return Quantity<Unit_minus<U1, U2>>{x.val / y.val};
}

// Multiplication by scalar
template <typename U>
constexpr Quantity<U> operator*(Quantity<U> x, long double y) {
  return Quantity<U>{x.val * y};
}

// Multiplication by scalar (reverse order)
template <typename U>
constexpr Quantity<U> operator*(long double x, Quantity<U> y) {
  return Quantity<U>{x * y.val};
}

// User-defined literals for both floating-point and integer
constexpr Quantity<M> operator""_m(long double d) { return Quantity<M>{d}; }
constexpr Quantity<M> operator""_m(unsigned long long d) {
  return Quantity<M>{static_cast<long double>(d)};
}

constexpr Quantity<Kg> operator""_kg(long double d) { return Quantity<Kg>{d}; }
constexpr Quantity<Kg> operator""_kg(unsigned long long d) {
  return Quantity<Kg>{static_cast<long double>(d)};
}

constexpr Quantity<S> operator""_s(long double d) { return Quantity<S>{d}; }
constexpr Quantity<S> operator""_s(unsigned long long d) {
  return Quantity<S>{static_cast<long double>(d)};
}

// More literals (km, g, mg, ms, us, ns)
constexpr Quantity<M> operator""_km(long double d) {
  return Quantity<M>{1000 * d};
}

constexpr Quantity<M> operator""_km(unsigned long long d) {
  return Quantity<M>{1000 * static_cast<long double>(d)};
}

constexpr Quantity<Kg> operator""_g(long double d) {
  return Quantity<Kg>{d / 1000};
}

constexpr Quantity<Kg> operator""_g(unsigned long long d) {
  return Quantity<Kg>{static_cast<long double>(d) / 1000};
}

constexpr Quantity<Kg> operator""_mg(long double d) {
  return Quantity<Kg>{d / 1000000};
}

constexpr Quantity<Kg> operator""_mg(unsigned long long d) {
  return Quantity<Kg>{static_cast<long double>(d) / 1000000};
}

constexpr Quantity<S> operator""_ms(long double d) {
  return Quantity<S>{d / 1000};
}

constexpr Quantity<S> operator""_ms(unsigned long long d) {
  return Quantity<S>{static_cast<long double>(d) / 1000};
}

constexpr Quantity<S> operator""_us(long double d) {
  return Quantity<S>{d / 1000000};
}

constexpr Quantity<S> operator""_us(unsigned long long d) {
  return Quantity<S>{static_cast<long double>(d) / 1000000};
}

constexpr Quantity<S> operator""_ns(long double d) {
  return Quantity<S>{d / 1000000000};
}

constexpr Quantity<S> operator""_ns(unsigned long long d) {
  return Quantity<S>{static_cast<long double>(d) / 1000000000};
}

// Square function
template <typename U>
constexpr Quantity<Unit_plus<U, U>> square(Quantity<U> x) {
  return Quantity<Unit_plus<U, U>>(x.val * x.val);
}

// Comparison
template <typename U>
constexpr bool operator==(Quantity<U> x, Quantity<U> y) {
  return x.val == y.val;
}

template <typename U>
constexpr bool operator!=(Quantity<U> x, Quantity<U> y) {
  return x.val != y.val;
}

// Suffix helper
inline std::string suffix(int u, std::string_view x) {
  std::string suf;
  if (u) {
    suf += x;
    if (u != 1) suf += std::to_string(u);
  }
  return suf;
}

// Output
template <typename U>
std::ostream& operator<<(std::ostream& os, Quantity<U> v) {
  return os << v.val << " " << suffix(U::m, "m") << suffix(U::kg, "kg")
            << suffix(U::s, "s");
}

int main() {
  auto distance{10_m};          // 10 meters
  auto time{20_s};              // 20 seconds
  auto speed{distance / time};  // .5 m/s

  // if (speed == 20)  // error : 20 is dimensionless
  // if (speed == distance)  // error : can’t compare m to m/s

  auto acceleration = distance / square(time);
  std::cout << "speed = " << speed << " acceleration = " << acceleration
            << "\n";
  // Output: speed = 0.5 ms-1 acceleration = 0.025 ms-2

  std::cout << "distance + distance = " << distance + distance << "\n";
  // Output: distance + distance = 20 m

  std::cout << "distance square = " << distance * distance << "\n";
  // Output: distance square = 100 m2

  std::cout << "speed / distance = " << speed / distance << "\n";
  // Output: speed / distance = 0.05 s-1

  auto time1{20_s};
  auto time2{200_ms};
  std::cout << "time1 + time2 = " << time1 + time2 << "\n";
}
