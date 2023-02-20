
// Desk Calculator
// From: The C++ Programming Language (4th Edition), Bjarne Stroustrup

#include <iostream>
#include <map>
#include <sstream>
#include <string>

// Types
enum class Kind : char {
  name,
  number,
  end,
  plus = '+',
  minus = '-',
  mul = '*',
  div = '/',
  print = ';',
  assign = '=',
  lp = '(',
  rp = ')'
};

struct Token {
  Kind kind;
  std::string string_value;
  double number_value;
};

class Token_stream {
 public:
  Token_stream(std::istream& s) : ip{&s}, owns{false} {}
  Token_stream(std::istream* p) : ip{p}, owns{true} {}
  ~Token_stream() { close(); }
  Token get();                      // read and return next token
  Token& current() { return ct; };  // most recently read token
  void set_input(std::istream& s) {
    close();
    ip = &s;
    owns = false;
  }
  void set_input(std::istream* p) {
    close();
    ip = p;
    owns = true;
  }

 private:
  void close() {
    if (owns) delete ip;
  }
  std::istream* ip;     // pointer to an input stream
  bool owns;            // does the Token_stream own the istream?
  Token ct{Kind::end};  // current token
};

// variables
Token_stream ts{std::cin};  // use input from cin
std::map<std::string, double> table;
int no_of_errors;

// Functions
double expr(bool);

double error(const std::string& s) {
  no_of_errors++;
  std::cerr << "error: " << s << '\n';
  return 1;
}

double prim(bool get)  // handle primaries
{
  if (get) ts.get();  // read next token
  switch (ts.current().kind) {
    case Kind::number:  // floating-point constant
    {
      double v = ts.current().number_value;
      ts.get();
      return v;
    }

    case Kind::name: {
      double& v = table[ts.current().string_value];  // find the corresponding
      if (ts.get().kind == Kind::assign)
        v = expr(true);  // ’=’ seen: assignment
      return v;
    }

    case Kind::minus:  // unary minus
      return -prim(true);

    case Kind::lp: {
      auto e = expr(true);
      if (ts.current().kind != Kind::rp) return error("')' expected");
      ts.get();  // eat ’)’
      return e;
    }
    default:
      return error("primary expected");
  }
}

double term(bool get)  // multiply and divide
{
  double left = prim(get);
  for (;;) {
    switch (ts.current().kind) {
      case Kind::mul:
        left *= prim(true);
        break;
      case Kind::div:
        if (auto d = prim(true)) {
          left /= d;
          break;
        }
        return error("divide by 0");
      default:
        return left;
    }
  }
}

double expr(bool get)  // add and subtract
{
  double left = term(get);

  for (;;) {  // forever
    switch (ts.current().kind) {
      case Kind::plus:
        left += term(true);
        break;

      case Kind::minus:
        left -= term(true);
        break;
      default:
        return left;
    }
  }
}

Token Token_stream::get() {
  char ch;

  do {  // skip whitespace except ’\n’
    if (!ip->get(ch)) return ct = {Kind::end};
  } while (ch != '\n' && isspace(ch));

  switch (ch) {
    case ';':
    case '\n':
      return ct = {Kind::print};
    case '*':
    case '/':
    case '+':
    case '-':
    case '(':
    case ')':
    case '=':
      return ct = {static_cast<Kind>(ch)};
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '.':
      ip->putback(ch);  // put the first digit (or .) back into the input stream
      *ip >> ct.number_value;  // read number into ct
      ct.kind = Kind::number;
      return ct;

    default:  // NAME, NAME=, or error
      if (isalpha(ch)) {
        std::string string_value{ch};
        while (ip->get(ch) && isalnum(ch))
          string_value += ch;  // append ch to end of string_value
        ip->putback(ch);
        return ct = {Kind::name, string_value};
      }

      error("bad token");
      return ct = {Kind::print};
  }
}

void calculate() {
  for (;;) {
    ts.get();
    if (ts.current().kind == Kind::end) break;
    if (ts.current().kind == Kind::print) continue;
    std::cout << expr(false) << '\n';
  }
}

int main(int argc, char* argv[]) {
  table["pi"] = 3.1415926535897932385;  // insert predefined names
  table["e"] = 2.7182818284590452354;

  // argc = 2;
  switch (argc) {
    case 1:  // read from standard input
      break;
    case 2:  // read from argument string
      ts.set_input(new std::istringstream{argv[1]});
      // ts.set_input(new std::istringstream{
      //     "x1a = 41;y2b = 32 + x1a;x1a + y2b;x1a * y2b"});
      break;
    default:
      error("too many arguments");
      return 1;
  }

  calculate();

  return no_of_errors;
}