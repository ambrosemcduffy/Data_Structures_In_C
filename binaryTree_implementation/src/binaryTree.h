#ifndef HEADER_BINARYTREE_H
#define HEADER_BINARYTREE_H
#include <string>
#include <iostream>
#include <stdio.h>

class Node
{
  /*
    Node Container class for string objects
    @param value: string const values..
  */
public:
  void setValue(std::string &&);
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

class Tree
{
  /*
    Binary Search Tree Data structure..
  */
private:
  Node *root = nullptr;
  Node *newNode = nullptr;
  void const deleteMemory(Node *);
  void const copyValues(Node *);

public:
  Tree()
  {
    printf("Allocating memory\n");
    newNode = (Node *)malloc(sizeof(Node));
  }
  ~Tree()
  {
    printf("deallocating memory\n");
    this->deleteMemory(root);
    free(newNode);
  }

  Tree(Tree &source)
  {
    printf("Copying values from %p to %p\n", &source, this);
    newNode = (Node *)malloc(sizeof(Node));
    copyValues(source.root);
  }

  Tree &operator=(Tree &source)
  {
    printf("Copying values from %p to %p\n", &source, this);
    if (&source == this)
    {
      return *this;
    }
    newNode = (Node *)malloc(sizeof(Node));
    copyValues(source.root);
    return *this;
  }

  Tree(Tree &&source)
  {
    printf("Moving values from %p to %p\n", &source, this);
    copyValues(source.root);
    deleteMemory(source.root);
    source.root = nullptr;
  }

  Tree &operator=(Tree &&source)
  {
    printf("Moving values from %p to %p\n", &source, this);
    if (&source == this)
    {
      return *this;
    }
    copyValues(source.root);
    deleteMemory(source.root);
    source.root = nullptr;
    return *this;
  }

  void setRoot(Node *newValue);
  Node *getRoot() const;
  void insert(std::string &&);
};

#endif