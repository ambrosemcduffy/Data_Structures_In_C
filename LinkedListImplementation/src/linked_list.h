#ifndef HEADER_LINKEDLIST_H
#define HEADER_LINKEDLIST_H

#include <string>

class Node {
public:
  Node(std::string value_) : value(value_) {}
  std::string value;
  Node *next = nullptr;
};

class Linkedlist {
public:
  Node *head = nullptr;
  Node *tail = nullptr;
  int num_entries = 0;

  void append(std::string value);
  std::string pop();
  void remove(std::string target);
  void printList();
  int getSize();
};

#endif