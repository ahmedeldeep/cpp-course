
// Modules

// math.cc - Module Declaration File
module;  // global module fragment

export module math;

export {  // Export Group
  double add(double a, double b) { return a + b; }
  double sub(double a, double b) { return a - b; }
  double mul(double a, double b) { return a * b; }
}