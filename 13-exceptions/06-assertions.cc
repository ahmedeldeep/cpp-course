
#include <iostream>
#include <string>
#include <vector>

enum class error_action { ignore, throwing, terminating, logging };
constexpr error_action default_error_action = error_action::throwing;

enum class error_code { default_exception, range_error, length_error };
const std::vector<std::string> error_code_name{"default exception",
                                               "range error", "length error"};
constexpr error_code default_error_code = error_code::default_exception;

template <error_action action = default_error_action,
          error_code code = default_error_code, class C>
constexpr void expect(C cond) {
  if constexpr (action == error_action::logging)
    if (!cond())
      std::cerr << "expect() failure: " << int(code) << " "
                << error_code_name[int(code)] << '\n';

  if constexpr (action == error_action::throwing)
    if (!cond()) throw code;

  if constexpr (action == error_action::terminating)
    if (!cond()) std::terminate();
}

template <int size>
class MyVector {
 public:
  MyVector() : _vec(size) { static_assert(size >= 0, "size is negative"); }

 private:
  std::vector<int> _vec;
};

int main() {
  //
  MyVector<10> vec;

  expect<error_action::logging, error_code::length_error>([] { return false; });
}
