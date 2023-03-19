
#include <cstdio>  // for file operations
#include <iostream>
#include <stdexcept>  // for std::runtime_error

// void use_file(const char* filename) {
//   std::FILE* file = std::fopen(filename, "r");
//   // use the file
//   std::fclose(file);
// }

// void use_file(const char* filename) {
//   std::FILE* file = std::fopen(filename, "r");
//   try {
//     // use the file
//   } catch (...) {  // catch every possible exception
//     std::fclose(file);
//     throw;
//   }
//   std::fclose(file);
// }

class FileHandler {
 public:
  FileHandler(const char* filename, const char* mode)
      : file{std::fopen(filename, mode)} {
    if (file == nullptr) throw std::runtime_error{"Can't open file"};
  }
  // TODO: implement other constructors, e.g. move & copy
  ~FileHandler() { std::fclose(file); }
  operator std::FILE*() { return file; }  // implicit conversion operator

 private:
  std::FILE* file;
};

void use_file(const char* filename) {
  FileHandler fh{filename, "r"};
  // use the file
  char buf[50];
  while (std::fgets(buf, sizeof buf, fh) != nullptr) {
    std::cout << buf;
  }
  std::cout << '\n';
}

int main() {
  //
  use_file("../CMakeLists.txt");
}