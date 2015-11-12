/*
 * binary_search_tree.h
 * Copyright (C) 2015 Sean Kirmani <sean@kirmani.io>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H_

#include "../vector/vector.h"

template <typename T>
class BinarySearchTree {
 private:
  struct Node {
    T data;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
  };

  Node* root_;

  void InorderTraversalHelper_(Node* node, Vector<T>* vector) {
    if (node != nullptr) {
      InorderTraversalHelper_(node->left, vector);
      vector->Append(node->data);
      InorderTraversalHelper_(node->right, vector);
    }
  }
  void PreorderTraversalHelper_(Node* node, Vector<T>* vector) {
    if (node != nullptr) {
      vector->Append(node->data);
      InorderTraversalHelper_(node->left, vector);
      InorderTraversalHelper_(node->right, vector);
    }
  }
  void postorderTraversalHelper_(Node* node, Vector<T>* vector) {
    if (node != nullptr) {
      postorderTraversalHelper_(node->left, vector);
      postorderTraversalHelper_(node->right, vector);
      vector->Append(node->data);
    }
  }

 public:
  BinarySearchTree() {
    root_ = nullptr;
  }

  void Insert(T val) {
    Node* child = new Node;
    child->data = val;

    if (root_ == nullptr) {
      root_ = child;
      return;
    }

    Node* p = root_;
    Node* parent = nullptr;
    while (p != nullptr) {
      parent = p;
      if (val < p->data) {
        p = p->left;
      } else {
        p = p->right;
      }
    }

    if (val < parent->data) {
      parent->left = child;
    } else {
      parent->right = child;
    }
    child->parent = parent;
  }

  Vector<T> InorderTraversal() {
    Vector<T> result;
    InorderTraversalHelper_(root_, &result);
    return result;
  }

  Vector<T> PreorderTraversal() {
    Vector<T> result;
    PreorderTraversalHelper_(root_, &result);
    return result;
  }

  Vector<T> PostorderTraversal() {
    Vector<T> result;
    postorderTraversalHelper_(root_, &result);
    return result;
  }
};

#endif  // BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H_
