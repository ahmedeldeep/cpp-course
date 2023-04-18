
// Modules

// clang-format off
// Generate precompiled module file
// clang++ -std=c++20 -c -Xclang -emit-module-interface math.cc -o math.pcm

// Compile C++ unit which uses module file.
// clang++ -std=c++20 -fmodules -c -fprebuilt-module-path=. main.cc -o main.o

// Generate executable
// clang++ -std=c++20 -fmodules -o main main.o math.pcm

// Building with separate module interface and implementation units
// clang++ -std=c++20 -c -Xclang -emit-module-interface 04-math-if.cc -o math.pcm
// clang++ -std=c++20 -fmodules -c -fprebuilt-module-path=. 04-math-imp.cc
// clang++ -std=c++20 -fmodules -c -fprebuilt-module-path=. main.cc
// clang++ -std=c++20 -fmodules -o main main.o 04-math-imp.o math.pcm
// clang-format on

// clang-format off
// Building submodules
// clang++ -std=c++20 -c -Xclang -emit-module-interface 06-math-p1.cc -o math.p1.pcm
// clang++ -std=c++20 -c -Xclang -emit-module-interface 06-math-p2.cc -o math.p2.pcm
// clang++ -std=c++20 -c -fprebuilt-module-path=. -Xclang -emit-module-interface 06-math.cc -o math.pcm
// clang++ -std=c++20 -fmodules -c -fprebuilt-module-path=. main.cc
// clang++ -std=c++20 -fmodules -o main main.o math.p1.pcm math.p2.pcm math.pcm
// clang-format on

// clang-format off
// Building module partitions
// clang++ -std=c++20 -c -Xclang -emit-module-interface 07-math-p1.cc -o math-p1.pcm
// clang++ -std=c++20 -c -Xclang -emit-module-interface 07-math-p2.cc -o math-p2.pcm
// clang++ -std=c++20 -c -fprebuilt-module-path=. -Xclang -emit-module-interface 07-math.cc -o math.pcm
// clang++ -std=c++20 -fmodules -c -fprebuilt-module-path=. main.cc
// clang++ -std=c++20 -fmodules -o main main.o math-p1.pcm math-p2.pcm math.pcm
// clang-format on

// main.cc
import<iostream>;

import math; // Error if import math:p1;

int main() {  //
  std::cout << "Hello Modules" << std::endl;
  std::cout << "3 + 5 = " << add(3, 5) << std::endl;
}
