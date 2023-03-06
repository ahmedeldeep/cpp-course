
// Overloaded Functions

// void print(int);          // print an int
// void print(const char*);  // print a C-style string

// ***

// void print(double);
// void print(long);

// void f() {
//   print(1L);   // print(long)
//   print(1.0);  // print(double)
//   print(1);    // error, ambiguous: print(long(1)) or print(double(1))?
// }

// ***

void print(int);
void print(const char*);
void print(double);
void print(long);
void print(char);

void h(char c, int i, short s, float f) {
  print(c);    // exact match: invoke print(char)
  print(i);    // exact match: invoke print(int)
  print(s);    // integral promotion: invoke print(int)
  print(f);    // float to double promotion: print(double)
  print('a');  // exact match: invoke print(char)
  print(49);   // exact match: invoke print(int)
  print(0);    // exact match: invoke print(int)
  print("a");  // exact match: invoke print(const char*)
  print(
      nullptr);  // nullptr_t to const char* promotion: invoke print(cost char*)
}

void f(int);
void g() {
  void f(double);
  f(1);  // call f(double)
}

void f1(char);
void f1(long);
void f2(char*);
void f2(int*);

void k(int i) {
  f1(i);                     // ambiguous: f1(char) or f1(long)?
  f2(0);                     // ambiguous: f2(char*) or f2(int*)?
  f2(static_cast<int*>(0));  // OK
}

int main() {
  //
}