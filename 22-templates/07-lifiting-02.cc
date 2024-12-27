
#include <functional>
#include <iostream>

double add_all(double* array, int num_elements) {
  double sum{0};
  for (int i = 0; i < num_elements; ++i) {
    sum = sum + array[i];
  }
  return sum;
}

struct Node {
  Node* next;
  int data;
};

int sum_elements(Node* first, Node* last) {
  int sum{0};
  while (first != last) {
    sum += first->data;
    first = first->next;
  }
  return sum;
}

template <typename Iter, typename Val>
Val sum(Iter first, Iter last) {
  Val sum{0};
  while (first != last) {
    sum += *first;
    ++first;
  }
  return sum;
}

class NodeIter {
 public:
  NodeIter(Node* node) : _node{node} {}
  NodeIter& operator++() {
    _node = _node->next;
    return *this;
  }
  int operator*() const { return _node->data; }
  bool operator!=(const NodeIter& other) const { return _node != other._node; }

 private:
  Node* _node;
};

template <typename Iter, typename Val, typename Oper>
Val accumulate(Iter first, Iter last, Val init, Oper op) {
  Val result = init;
  while (first != last) {
    result = op(result, *first);
    ++first;
  }
  return result;
}

int main() {
  //
  double numbers[] = {1, 2, 3, 4};
  std::cout << sum<double*, double>(numbers, numbers + 4) << '\n';

  Node last{nullptr, 0};
  Node forth{&last, 4};
  Node third{&forth, 3};
  Node second{&third, 2};
  Node first = {&second, 1};
  std::cout << sum<NodeIter, int>(NodeIter{&first}, NodeIter{&last}) << '\n';

  std::cout << accumulate(numbers, numbers + 4, 2, std::multiplies<double>())
            << '\n';
  std::cout << accumulate(NodeIter{&first}, NodeIter{&last}, 0,
                          std::plus<int>())
            << '\n';
}