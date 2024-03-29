﻿#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

template <typename T>
struct BinaryTree;

template <typename T>
struct Node {
  T value = T();
  Node<T>* left = nullptr;
  Node<T>* right = nullptr;
  Node<T>* parent = nullptr;
  BinaryTree<T>* tree = nullptr;

  explicit Node(const T& value) : value(value) {}

  Node(const T& value, Node<T>* const left, Node<T>* const right)
      : value(value), left(left), right(right) {
    this->left->tree = this->right->tree = tree;
    this->left->parent = this->right->parent = this;
  }

  void set_tree(BinaryTree<T>* t) {
    tree = t;
    if (left) left->set_tree(t);
    if (right) right->set_tree(t);
  }

  ~Node() {
    if (left) delete left;
    if (right) delete right;
  }
};

template <typename T>
struct BinaryTree {
  Node<T>* root = nullptr;

  explicit BinaryTree(Node<T>* const root) : root(root) {
    root->set_tree(this);
  }

  ~BinaryTree() {
    if (root) delete root;
  }

  template <typename U>
  struct BinaryTreeIterator {
    Node<U>* current;

    explicit BinaryTreeIterator(Node<U>* current) : current(current) {}

    bool operator!=(const BinaryTreeIterator<U>& other) {
      return current != other.current;
    }

    // no continuations in C++ (unlike C#)
    BinaryTreeIterator<U>& operator++() {
      if (current->right) {
        current = current->right;
        while (current->left) current = current->left;
      } else {
        Node<T>* p = current->parent;
        while (p && current == p->right) {
          current = p;
          p = p->parent;
        }
        current = p;
      }
      return *this;
    }

    Node<U>& operator*() { return *current; }
  };
  typedef BinaryTreeIterator<T> iterator;

  iterator end() { return iterator{nullptr}; }

  iterator begin() {
    Node<T>* n = root;

    if (n)
      while (n->left) n = n->left;
    return iterator{n};
  }
};

void std_iterators() {
  vector<string> names{"john", "jane", "jill", "jack"};

  vector<string>::iterator it = names.begin();  // or begin(names)
  cout << "first name is " << *it << "\n";

  ++it;  // advance the iterator
  it->append(string(" goodall"));
  cout << "second name is " << *it << "\n";

  //  while (++it != names.end())
  while (!(++it == names.end())) {
    cout << "another name: " << *it << "\n";
  }

  // traversing the entire vector backwards
  // note global rbegin/rend, note ++ not --
  // expand auto here
  for (auto ri = rbegin(names); ri != rend(names); ++ri) {
    cout << *ri;
    if (ri + 1 != rend(names))  // iterator arithmetic
      cout << ", ";
  }
  cout << endl;

  // constant iterators
  vector<string>::const_reverse_iterator jack = crbegin(names);
  // won't work
  //*jack += "test";
}

// in order traversal
void binary_tree_iterator() {
  BinaryTree<string> family{new Node<string>{
      "me",
      new Node<string>{"mother", new Node<string>{"mother's mother"},
                       new Node<string>{"mother's father"}},
      new Node<string>{"father"}}};

  // pre order traversal
  for (auto it = family.begin(); it != family.end(); ++it) {
    cout << (*it).value << endl;
  }
}

int main() {
  // std_iterators();
  binary_tree_iterator();

  return 0;
}
