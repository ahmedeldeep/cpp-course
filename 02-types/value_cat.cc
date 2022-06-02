
int var = 20;  // NOLINT

int& fun1() { return var; }
int fun2() { return var; }

int main() {
  int var1 = 4;         // var1 is lvalue, 4 is rvalue
  int* pvar = &var1;    // NOLINT - pvar is lvalue, &var1 is rvalue
  int var2 = var1 + 4;  // NOLINT - (var1 + 4) is rvalue
  // &var1 = 10;  // error: lvalue required as left operand of assignment
  (var1 = 4) = 10;  // (var1 = 4) is lvalue
  // (var1 + 4) = 10;  // error: lvalue required as left operand of assignment

  // NOLINTNEXTLINE
  int x1 = fun1();  // fun1() is lvalue
  fun1() = 10;

  // NOLINTNEXTLINE
  int x2 = fun2();  // fun2() is rvalue
  // fun2() = 10;      // error: lvalue required as left operand of assignment
}
