
#include <iostream>
#include <string>

struct BuffControl {
  std::size_t last_read{0};
  std::size_t last_write{0};
};

template <typename T, std::size_t N>
class Buffer {
 public:
  Buffer() : ctrl(new BuffControl) {}
  ~Buffer() { delete ctrl; }
  void write(T data);
  T read() const;

 private:
  T elem[N]{};
  BuffControl* ctrl;
};

template <typename T, std::size_t N>
void Buffer<T, N>::write(T data) {
  elem[ctrl->last_write] = data;
  ctrl->last_write++;
  // ...
}

template <typename T, std::size_t N>
T Buffer<T, N>::read() const {
  return elem[ctrl->last_read++];
  // ...
}

int main() {
  //
  Buffer<std::string, 4> buff;
  buff.write("Hello");
  buff.write("World");
  std::cout << buff.read() << " " << buff.read() << "\n";
}