
#include <iostream>

template <typename T>
class Node;

Node<int>* n1;  // no instantiation of Node<int> needed

template <typename T>
class Node {
  Node* next;  // OK: no definition of Node needed
  // ...
};

Node<int> n2;  // now we need to instantiate Node<int>

int main() {  //
}