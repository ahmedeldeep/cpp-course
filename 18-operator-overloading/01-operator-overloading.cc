
#include <initializer_list>

template <typename T>
class Array {
 public:
  Array(std::initializer_list<T> list)
      : _elem(new T[list.size()]), _size(list.size()) {
    for (auto i = 0; i < list.size(); ++i) {
      _elem[i] = list.begin()[i];
    }
  }
  ~Array() { delete[] _elem; };

 private:
  T* _elem;
  std::size_t _size;
};

int main() {
  //
  Array a1{1, 2, 3, 4};
  Array a2{5, 6, 7, 8};
  Array a3 = a1 + 1;   // error
  Array a4 = a1 + a2;  // error
}
