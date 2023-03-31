// Vector Example
// Source: The C++ Programming Language (4th Edition), Bjarne Stroustrup

//  ________
// |        | (elem) start of elements space - start of allocation space
// |        |
// |________| (space) end of elements space - start of extra space
// |        |
// |________| (last) end of extra space - end of allocation space

#include <memory>

template <class T, class A = std::allocator<T>>
class vector {
 public:
  using size_type = unsigned int;  // type used for vector sizes

  explicit vector(size_type n, const T& val = T(), const A& = A());
  vector(const vector& a);             // copy constructor
  vector& operator=(const vector& a);  // copy assignment
  vector(vector&& a);                  // move constructor
  vector& operator=(vector&& a);       // move assignment
  ~vector();

  size_type size() const { return _space - _elem; }
  size_type capacity() const { return _last - _elem; }
  void reserve(size_type n);                // increase capacity to n
  void resize(size_type n, const T& = {});  // increase size to n
  void push_back(const T&);                 // add an element at the end

  // TODO: Iterators

 private:
  T* _elem;   // start of allocation
  T* _space;  // end of element sequence, start of space allocated for possible
              // expansion
  T* _last;   // end of allocated space
  A _alloc;   // allocator
};
