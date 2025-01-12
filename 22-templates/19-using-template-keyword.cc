
#include <iostream>

template <typename T>
class Node {
 public:
  Node(Node* next, T data) : next{next}, data{data} {}
  Node* next;
  T data;
};

template <typename T>
class NodeIter {
 public:
  NodeIter(Node<T>* node) : _node{node} {}
  template <typename U>
  U getData() const {
    return _node->data;
  }

 private:
  Node<T>* _node;
};

template <typename Iterator, typename T>
void print_data(Iterator& iter) {
  std::cout << iter.template getData<T>() << std::endl;
  // without template the compiler will give error:
  // use 'template' keyword to treat 'getData' as
  // a dependent template name
}

int main() {
  Node<int> n1{nullptr, 1};
  NodeIter iter{&n1};
  print_data<NodeIter<int>, int>(iter);

  return 0;
}