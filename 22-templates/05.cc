#include <iostream>

// function
template <typename T>
bool Check_f(T value, T max, T min) {
  return value <= max && value >= min;
}

// function object
template <typename T>
class Check {
 public:
  Check(T max, T min) : _max(max), _min(min) {}
  bool operator()(T value) const { return value <= _max && value >= _min; }

 private:
  T _max, _min;
};

int main() {
  //
  bool res1 = Check_f(50, 80, 10);

  Check check(80, 10);
  bool res2 = check(50);
}