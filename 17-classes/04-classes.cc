
#include <iostream>
#include <string>

template <typename T, std::size_t N>
class Buffer {
 public:
  void write(T data);
  T read() const;

 private:
  T elem[N]{};
  mutable std::size_t last_read{0};
  std::size_t last_write{0};
};

template <typename T, std::size_t N>
void Buffer<T, N>::write(T data) {
  elem[last_write] = data;
  last_write++;
  // ...
}

template <typename T, std::size_t N>
T Buffer<T, N>::read() const {
  return elem[last_read++];
  // ...
}

int main() {
  //
  Buffer<std::string, 4> buff;
  buff.write("Hello");
  buff.write("World");
  std::cout << buff.read() << " " << buff.read() << "\n";
}