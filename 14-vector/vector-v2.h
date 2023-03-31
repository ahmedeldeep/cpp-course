// Vector Example
// Source: The C++ Programming Language (4th Edition), Bjarne Stroustrup

//  ________
// |        | (elem) start of elements space - start of allocation space
// |        |
// |________| (space) end of elements space - start of extra space
// |        |
// |________| (last) end of extra space - end of allocation space

#include <memory>

template <typename T, typename A = std::allocator<T>>
struct vector_base {
  vector_base(const A& a, typename A::size_type n, typename A::size_type m = 0)
      : _alloc{a},
        _elem{_alloc.allocate(n + m)},
        _space{_elem + n},
        _last{_elem + n + m} {}

  ~vector_base() { _alloc.deallocate(_elem, _last - _elem); }

  vector_base(const vector_base&) = delete;  // no copy operations
  vector_base& operator=(const vector_base&) = delete;

  vector_base(vector_base&&);             // move constructor
  vector_base& operator=(vector_base&&);  // move assignment

  A _alloc;   // allocator
  T* _elem;   // start of allocation
  T* _space;  // end of element sequence, start of space allocated for possible
              // expansion
  T* _last;   // end of allocated space
};

template <typename T, typename A = std::allocator<T>>
class vector {
 public:
  using size_type = typename A::size_type;

  explicit vector(size_type n, const T& val = T{}, const A& alloc = A{});

  vector(const vector& other);             // copy constructor
  vector& operator=(const vector& other);  // copy assignment

  vector(vector&& other);             // move constructor
  vector& operator=(vector&& other);  // move assignment

  ~vector() { destroy_elements(); }

  size_type size() const { return _vb._space - _vb._elem; }
  size_type capacity() const { return _vb._last - _vb._elem; }

  void reserve(size_type);                // increase capacity
  void resize(size_type, const T& = {});  // change the number of elements
  void clear() { resize(0); }             // make the vector empty
  void push_back(const T&);               // add an element at the end

  // TODO: Iterators

 private:
  vector_base<T, A> _vb;
  void destroy_elements();
};