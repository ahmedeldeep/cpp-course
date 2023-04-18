
// Modules

// math.cc - Module Declaration File
module;  // global module fragment

export module math;

export {  // Export Group
  template <typename T1, typename T2>
  auto add(T1 a, T2 b) {
    return a + b;
  }

  template <typename T1, typename T2>
  auto sub(T1 a, T2 b) {
    return a - b;
  }

  template <typename T1, typename T2>
  auto mul(T1 a, T2 b) {
    return a * b;
  }
}