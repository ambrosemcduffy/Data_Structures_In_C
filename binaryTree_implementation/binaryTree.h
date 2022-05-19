#ifndef HEADER_BINARYTREE_H
#define HEADER_BINARYTREE_H
#include <string>

class Node {
public:
  void setValue(std::string);
  void setLeft(Node *);
  void setRight(Node *);
  std::string getValue();
  Node *getLeft();
  Node *getRight();
  bool hasLeft();
  bool hasRight();
  Node(std::string value_) : value(value_) {}

private:
  Node *left = nullptr;
  Node *right = nullptr;
  std::string value;
};

class Tree {
private:
  Node *root = nullptr;

public:
  void setRoot(std::string);
  Node *getRoot();
  void insert(std::string);
};

#endif