#ifndef HEADER_BINARYTREE_H
#define HEADER_BINARYTREE_H
#include <string>
#include <iostream>
#include <stdio.h>

class Node {
public:
  void setValue(std::string &);
  void setLeft(Node *&);
  void setRight(Node *&);
  std::string getValue() const;
  Node *getLeft() const;
  Node *getRight() const;
  bool hasLeft() const;
  bool hasRight() const;
  Node(std::string const &value_) : value(value_) {}
private:
  Node *left = nullptr;
  Node *right = nullptr;
  std::string value;
};

class Tree {
private:
  Node *root = nullptr;
  Node *newNode = nullptr;

public:
  void setRoot(Node *newValue);
  Node *getRoot() const;
  void insert(std::string);
  Tree(){
    printf("Allocating memory\n");
    //root = (Node *)malloc(sizeof(Node));
    newNode = (Node *)malloc(sizeof(Node));
  }
  ~Tree(){
    printf("deallocating memory\n");
    //free(root);
    free(newNode);
  }
};

#endif