
#include <vector>

namespace Calculator {
double add(double, double);
double sub(double, double);
double multiply(double a, double b) { return a * b; }
}  // namespace Calculator

double Calculator::add(double a, double b)  // definition
{
  return a + b;
}
double val = Calculator::add(1, 2);  // use

// double Calculator::divide(double, double);   // error : no divide()
// double Calculator::multply(double, double);  // error : (misspelling)
// double Calculator::add(int, int);            // error : (wrong type)

using Calculator::multiply;
double val2 = multiply(1, 2);

using namespace std;  // make every name from std accessible

// graphics library
namespace Graph_lib {
class Line {};
}  // namespace Graph_lib

// text manipulation library
namespace Text_lib {
class Line {};
}  // namespace Text_lib

using namespace Graph_lib;
using namespace Text_lib;

// vector<Line> vec;  // error: reference to 'Line' is ambiguous

namespace shapes {
struct point {
  int x;
  int y;
};
void print(point&) {
  // ...
}
}  // namespace shapes

void fun(shapes::point& pt) { print(pt); }

namespace N {
template <class T>
void f(T, int) {}  // N::f()
class X {};
}  // namespace N

namespace N2 {
N::X x;
void f(N::X, unsigned);
void g() {
  f(x, 1);  // calls N::f(X,int)
}
}  // namespace N2

namespace A {
int f();  // now A has member f()
}
namespace A {
int g();  // now A has two members, f() and g()
}

namespace this_is_very_long_namespace_name {
struct point {
  int x;
  int y;
};
}  // namespace this_is_very_long_namespace_name

this_is_very_long_namespace_name::point pt1;

namespace short_name = this_is_very_long_namespace_name;  // Alias
short_name::point pt2;

namespace lib_1 {
class Line {};
}  // namespace lib_1

namespace lib_2 {
class Text {};
}  // namespace lib_2

namespace my_lib {
using namespace lib_1;
using namespace lib_2;
}  // namespace my_lib

my_lib::Line L1;
my_lib::Text T1;

namespace Interface {
inline namespace V3 {  // default
double f(double);
int f(int);
template <class T>
class C {};
}  // namespace V3

namespace V2 {
// ...
}

namespace V1 {
double f(double);
template <class T>
class C {};
}  // namespace V1
}  // namespace Interface

#include "interface.h"

int main() {
  //
  Library::print();      // default from V2
  Library::print_new();  // default from V3
}