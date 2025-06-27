
#include <array>
#include <iostream>
#include <type_traits>

template <typename T>
struct StackAllocator {
 public:
  StackAllocator() = default;
  T& operator*() { return obj; }
  T* operator->() { return &obj; }
  StackAllocator(const StackAllocator&) = delete;  // prevent copying
  StackAllocator operator=(const StackAllocator&) = delete;

 private:
  T obj;  // the object
};

template <typename T>
struct HeapAllocator {
 public:
  HeapAllocator() : _ptr(new T) {}  // allocate
  ~HeapAllocator() { delete _ptr; }
  T& operator*() { return *_ptr; }
  T* operator->() { return _ptr; }
  HeapAllocator(const HeapAllocator&) = delete;  // prevent copying
  HeapAllocator operator=(const HeapAllocator&) = delete;

 private:
  T* _ptr;  // pointer to object on the free store
};

constexpr int on_stack_max = 10;

template <typename T>
struct Allocator_t {
  using type =
      typename std::conditional<(sizeof(T) <= on_stack_max),
                                StackAllocator<T>,  // first alternative
                                HeapAllocator<T>    // second alternative
                                >::type;
};

template <typename T>
using Allocator = typename Allocator_t<T>::type;

int main() {
  Allocator<double> x;
  Allocator<std::array<int, 20>> y;
}