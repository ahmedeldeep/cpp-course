
// Modules

// 05-math-w-private.cc
module;  // global module fragment

export module math;

export {
  double add(double a, double b);
  double sub(double a, double b);
  double mul(double a, double b);
}

module : private;  // private module fragment

double add(double a, double b) { return a + b; }
double sub(double a, double b) { return a - b; }
double mul(double a, double b) { return a * b; }