// main.cc
// Copyright (C) 2015 Sean Kirmani <sean@kirmani.io>
//
// Distributed under terms of the MIT license.

#include <iostream>
#include "./binary_search_tree.h"

int main() {
  BinarySearchTree<int> bst;
  bst.Insert(3);
  std::cout << bst.InorderTraversal() << std::endl;
  bst.Insert(2);
  std::cout << bst.InorderTraversal() << std::endl;
  bst.Insert(4);
  std::cout << bst.InorderTraversal() << std::endl;
  bst.Insert(5);
  std::cout << bst.InorderTraversal() << std::endl;
  bst.Insert(1);
  std::cout << bst.InorderTraversal() << std::endl;
}
