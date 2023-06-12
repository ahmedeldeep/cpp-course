
#include <initializer_list>
#include <iostream>
#include <ostream>

template <typename T>
class Array {
 public:
  Array(std::initializer_list<T> list)
      : _elem(new T[list.size()]), _size(list.size()) {
    for (auto i = 0; i < list.size(); ++i) {
      _elem[i] = list.begin()[i];
    }
  }

  Array(const Array&);             // copy constructor
  Array& operator=(const Array&);  // copy assignment
  Array(Array&&);                  // move constructor
  Array& operator=(Array&&);       // move assignment
  ~Array() { delete[] _elem; };

  T* begin() { return _elem; }
  const T* begin() const { return _elem; }
  T* end() { return _elem + _size; }
  const T* end() const { return _elem + _size; }
  constexpr std::size_t size() const { return _size; }
  void print();

  T& operator[](std::size_t n) { return _elem[n]; }
  const T& operator[](std::size_t n) const { return _elem[n]; }
  Array operator+(const Array&) const;
  Array operator+(const T&) const;
  Array& operator+=(const Array&);
  bool operator==(const Array&) const;
  template <typename U>
  friend std::ostream& operator<<(std::ostream& os, const Array<U>& array);
  Array& operator++();
  Array operator++(int);

 private:
  T* _elem;
  std::size_t _size;
};

// copy constructor
template <typename T>
Array<T>::Array(const Array<T>& source) {
  _elem = new T[source._size];
  _size = source._size;
  for (std::size_t i = 0; i < _size; i++) {
    _elem[i] = source[i];
  }
}

// copy assignment
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& source) {
  if (this == &source) return *this;
  if (_size != source._size) throw;
  for (std::size_t i = 0; i < _size; i++) {
    _elem[i] = source[i];
  }
  return *this;
}

// move constructor
template <typename T>
Array<T>::Array(Array<T>&& source) {
  _size = source._size;
  _elem = source._elem;
  source._elem = nullptr;
}

// move assignment
template <typename T>
Array<T>& Array<T>::operator=(Array<T>&& source) {
  delete[] _elem;
  _size = source._size;
  _elem = source._elem;
  source._elem = nullptr;
  return *this;
}

template <typename T>
void Array<T>::print() {
  for (std::size_t i = 0; i < _size; i++) {
    std::cout << _elem[i] << " ";
  }
  std::cout << "\n";
}

template <typename T>
Array<T> Array<T>::operator+(const Array& other) const {
  if (_size != other._size) throw;
  Array<T> result{*this};
  for (size_t i = 0; i < _size; i++) {
    result._elem[i] += other._elem[i];
  }
  return result;
}

template <typename T>
Array<T> Array<T>::operator+(const T& value) const {
  Array<T> result{*this};
  for (size_t i = 0; i < _size; i++) {
    result._elem[i] += value;
  }
  return result;
}

template <typename T>
Array<T>& Array<T>::operator+=(const Array& other) {
  if (_size != other._size) throw;
  for (size_t i = 0; i < _size; i++) {
    _elem[i] += other._elem[i];
  }
  return *this;
}

template <typename T>
bool Array<T>::operator==(const Array& other) const {
  if (_size != other._size) throw;
  bool result{true};
  for (size_t i = 0; i < _size; i++) {
    if (_elem[i] != other._elem[i]) return false;
  }
  return result;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& array) {
  for (std::size_t i = 0; i < array._size; i++) {
    os << array._elem[i] << " ";
  }
  os << "\n";
  return os;
}

template <typename T>
Array<T>& Array<T>::operator++() {
  for (size_t i = 0; i < _size; i++) {
    _elem[i] += 1;
  }
  return *this;
}

template <typename T>
Array<T> Array<T>::operator++(int) {
  Array<T> result{*this};
  for (size_t i = 0; i < _size; i++) {
    _elem[i] += 1;
  }
  return std::move(result);
}

int main() {
  //
  Array a1{1, 2, 3, 4};
  Array a2{5, 6, 7, 8};

  std::cout << "Before increment a1: " << a1;
  ++a1;
  std::cout << "After increment a1: " << a1;

  std::cout << "Before increment a2: " << a2;
  Array a3{a2++};
  a2++;
  std::cout << "After increment a2: " << a2;
  std::cout << "After increment a3: " << a3;
}
