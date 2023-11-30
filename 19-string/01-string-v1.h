
// String class
// Source: The C++ Programming Language (4th Edition), Bjarne Stroustrup

#include <stdexcept>

class String {
  // A simple string that implements the short string optimization.

  // size()==sz is the number of elements
  // if size() <= short_max, the characters are held in the String object
  // itself; otherwise the free store is used (short string optimization).

  // ptr points to the start of the character sequence
  // the character sequence is kept zero-terminated: ptr[size()]==0;
  // this allows us to use C library string functions and to easily return a
  // C-style string: c_str()

  // To allow efficient addition of characters at end, String grows by doubling
  // its allocation;
  // capacity() is the amount of space available for characters (excluding the
  // terminating 0): sz+space

 public:
  String();                          // default constructor
  String(const char* p);             // constructor for C-style string
  String(const String&);             // copy constructor
  String& operator=(const String&);  // copy assignment
  String(String&& x);                // move constructor
  String& operator=(String&& x);     // move assignment
  ~String();                         // destructor

  char& operator[](int n) { return ptr[n]; }  // unchecked element access
  char operator[](int n) const { return ptr[n]; }

  char& at(int n);  // range-checked element access
  char at(int n) const;

  String& operator+=(char c);    // add c at end
  char* c_str() { return ptr; }  // C-style string access
  const char* c_str() const { return ptr; }

  int size() const { return sz; }  // number of elements
  int capacity() const;            // elements plus available space

 private:
  static const int short_max = 15;
  std::size_t sz;  // number of characters
  char* ptr;
  union {
    int space;               // unused allocated space
    char ch[short_max + 1];  // leave space for terminating 0
  };

  void check(int n) const;  // range check

  // ancillary member functions:
  void copy_from(const String& x);
  void move_from(String& x);
};