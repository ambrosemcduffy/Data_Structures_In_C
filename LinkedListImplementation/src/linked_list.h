#ifndef HEADER_LINKEDLIST_H
#define HEADER_LINKEDLIST_H

#include <stdio.h>
#include <string>

class Node {
public:
  Node(std::string const &value_) : value(value_) {}
  std::string value;
  Node *next = nullptr;
};

class Linkedlist {
private:
  Node *new_node = nullptr;

public:
  Linkedlist() {
    printf("Allocating memory\n");
    tail = (Node *)malloc(sizeof(Node));
  }

  ~Linkedlist() {
    printf("Deallocating memory\n");
    Node *node = head;
    while (node) {
      Node *temp = node;
      node = node->next;
      free(temp);
    }
    free(tail);
  }

  Linkedlist(Linkedlist &source) {
    printf("Copying over members to new instance..\n");
    Node *source_node = source.head;
    while (source_node) {
      append(source_node->value);

      Node *temp = source_node;
      source_node = source_node->next;
      delete temp;
    }
    source.head = nullptr;
    source.tail = nullptr;
    source.num_entries = 0;
    source.new_node = nullptr;
  }

  Linkedlist &operator=(Linkedlist &source) {
    printf("Assigning - Copying over members to new instance..\n");
    Node *source_node = source.head;
    while (source_node) {
      append(source_node->value);

      Node *temp = source_node;
      source_node = source_node->next;
      delete temp;
    }
    source.head = nullptr;
    source.tail = nullptr;
    source.num_entries = 0;
    source.new_node = nullptr;
    return *this;
  }

  Linkedlist(Linkedlist &&source) {
    printf("Moving over members to new instance..\n");
    Node *source_node = source.head;
    while (source_node) {
      append(source_node->value);

      Node *temp = source_node;
      source_node = source_node->next;
      delete temp;
    }
    source.head = nullptr;
    source.tail = nullptr;
    source.num_entries = 0;
    source.new_node = nullptr;
  }

  Linkedlist &operator=(Linkedlist &&source) {
    printf("Assigning - Moving over members to new instance..\n");
    if (this == &source) {
      return *this;
    }
    Node *source_node = source.head;
    while (source_node) {
      append(source_node->value);

      Node *temp = source_node;
      source_node = source_node->next;
      delete temp;
    }
    source.head = nullptr;
    source.tail = nullptr;
    source.num_entries = 0;
    source.new_node = nullptr;
    return *this;
  }

  Node *head = nullptr;
  Node *tail = nullptr;
  int num_entries = 0;

  void append(std::string value);
  std::string pop();
  void remove(std::string target);
  void printList() const;
  int getSize() const;
};

#endif