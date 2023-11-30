
// String class
// Source: The C++ Programming Language (4th Edition), Bjarne Stroustrup

#include "01-string-v1.h"

#include <cstring>
#include <iostream>
#include <istream>
#include <ostream>

char* expand(const char* ptr, int n) {
  char* p = new char[n];
  std::strcpy(p, ptr);
  return p;
}

// default constructor : x{""}
// ptr points to elements
// ch is an initial location
String::String() : sz{0}, ptr{ch} {
  ch[0] = 0;  // terminating 0
}

// constructor for C-style string
String::String(const char* p)
    : sz{std::strlen(p)},
      ptr{(sz <= short_max) ? ch : new char[sz + 1]},
      space{0} {
  std::strcpy(ptr, p);  // copy characters into ptr from p
}

// copy constructor
String::String(const String& other) { copy_from(other); }

// copy assignment
String& String::operator=(const String& other) {
  if (this == &other) return *this;  // deal with self-assignment
  if (short_max < sz) delete[] ptr;
  copy_from(other);
  return *this;
}

// move constructor
String::String(String&& other) { move_from(other); }

// move assignment
String& String::operator=(String&& other) {
  if (this == &other) return *this;  // deal with self-assignment
  if (short_max < sz) delete[] ptr;
  move_from(other);
  return *this;
}

// destructor
String::~String() {
  if (short_max < sz) delete[] ptr;
}

// range-checked element access
char& String::at(int n) {
  check(n);
  return ptr[n];
}
char String::at(int n) const {
  check(n);
  return ptr[n];
}

// add c at end
String& String::operator+=(char c) {
  if (sz == short_max) {  // expand to long string
    // double the allocation (+2 because of the terminating 0)
    int n = sz + sz + 2;
    ptr = expand(ptr, n);
    space = n - sz - 2;
  } else if (short_max < sz) {
    if (space == 0) {  // expand in free store
      // double the allocation (+2 because of the terminating 0)
      int n = sz + sz + 2;
      char* p = expand(ptr, n);
      delete[] ptr;
      ptr = p;
      space = n - sz - 2;
    } else
      --space;
  }

  ptr[sz] = c;    // add c at end
  ptr[++sz] = 0;  // increase size and set terminator
  return *this;
}

// elements plus available space
int String::capacity() const {
  return (sz <= short_max) ? short_max : sz + space;
}

// range check
void String::check(int n) const {
  if (n < 0 || sz <= n) throw std::out_of_range("String::at()");
}

// make *this a copy of other
void String::copy_from(const String& other) {
  if (other.sz <= short_max) {  // copy *this
    std::memcpy(this, &other, sizeof(other));
    ptr = ch;
  } else {  // copy the elements
    ptr = expand(other.ptr, other.sz + 1);
    sz = other.sz;
    space = 0;
  }
}

void String::move_from(String& other) {
  if (other.sz <= short_max) {  // copy *this
    std::memcpy(this, &other, sizeof(other));
    ptr = ch;
  } else {  // grab the elements
    ptr = other.ptr;
    sz = other.sz;
    space = other.space;
    other.ptr = other.ch;  // other = ""
    other.sz = 0;
    other.ch[0] = 0;
  }
}

// Helper Functions

std::ostream& operator<<(std::ostream& os, const String& s) {
  return os << s.c_str();
}

std::istream& operator>>(std::istream& is, String& s) {
  s = "";         // clear the target string
  is >> std::ws;  // skip whitespace
  char ch = ' ';
  while (is.get(ch) && !std::isspace(ch)) s += ch;
  return is;
}

bool operator==(const String& a, const String& b) {
  if (a.size() != b.size()) return false;
  for (int i = 0; i != a.size(); ++i)
    if (a[i] != b[i]) return false;
  return true;
}

bool operator!=(const String& a, const String& b) { return !(a == b); }

char* begin(String& x) { return x.c_str(); }
char* end(String& x) { return x.c_str() + x.size(); }
const char* begin(const String& x) { return x.c_str(); }
const char* end(const String& x) { return x.c_str() + x.size(); }

// concatenation
String& operator+=(String& a, const String& b) {
  for (auto x : b) a += x;
  return a;
}

String operator+(const String& a, const String& b) {
  String res{a};
  res += b;
  return res;
}

// literal suffix
String operator"" _s(const char* p, size_t) { return String{p}; }

int main() {
  //
  String s1{"Hello Hello Hello Hello"};
  String s2{"World World World World"};
  String s3{s1};
  s3 = s2;
  s2 = std::move(s1);

  String s4{"Hello "};
  String s5{"World"};
  s5 += "!";
  String s6{s4 + s5};
  std::cout << s6 << "\n";
  String s7{"Hello"_s + "World!"_s};
}