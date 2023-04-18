
// 09-myheader-main.cc
import "09-myheader.h";

int main() { print_hello(); }

// clang-format off
// Building header units
// clang++ -std=c++20 -fmodule-header 09-myheader.h -o myheader.pcm
// clang++ -std=c++20 -fmodule-file=myheader.pcm -c 09-myheader.cc
// clang++ -std=c++20 -fmodule-file=myheader.pcm -o main 09-myheader.o 09-myheader-main.cc
// clang-format on