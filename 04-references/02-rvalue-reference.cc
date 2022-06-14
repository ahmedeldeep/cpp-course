
// References

#include <iostream>
#include <string>

std::string get_long_string() {
  return "This function returns very looooong string, which will be expansive "
         "to copy ";
}

int main() {
  //
  std::string str = get_long_string();

  std::string& r1{str};  // lvalue reference, bind r1 to var (an lvalue)

  std::string& r2{get_long_string()};  // error can not bind lvalue reference,
                                       // to temporary(rvalue)
  const std::string& r3{get_long_string()};  // ok: const can bind to rvalue

  std::string&& rr1{str};  // error: cannot bind rvalue reference to lvalue
  std::string&& rr2{get_long_string()};        // ok: rvalue reference to rvalue
  const std::string&& rr3{get_long_string()};  // no need to use it
}