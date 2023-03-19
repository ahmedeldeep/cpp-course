
#include <iostream>
#include <string>
#include <vector>

struct Some_error {
  std::string what;
};

int do_task() {
  int result = 0;
  if (result) {
    return result;
  } else {
    throw Some_error{"problem !!"};
  }
}

void taskmaster() {
  try {
    auto result = do_task();
    // use result
  } catch (Some_error error) {
    // failure to do_task: handle problem
    std::cout << error.what << std::endl;
  }
}

void test() {
  try {
    std::vector<int> vec(-10);

  } catch (std::length_error&) {
    std::cerr << "test failed: length error\n" << std::endl;
    throw;  // rethrow

  } catch (std::bad_alloc&) {
    std::cerr << "test failed: memory exhaustion\n" << std::endl;
    std::terminate();  // terminate the program
  }
}

// Generic Programming, C++14
template <typename T, typename U>
auto add(T t, U u)  // no need for the suffix return type syntax
{
  return t + u;
}

int main() {
  //
  taskmaster();
  try {
    test();
  } catch (...) {
  }
}
