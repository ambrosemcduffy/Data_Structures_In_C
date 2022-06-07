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

class Linkedlist
{
private:
  Node *new_node = nullptr;
  void const freeMemory(Node *);

public:
  Linkedlist()
  {
    printf("Allocating Memory\n");
    new_node = (Node *)malloc(sizeof(Node));
  }
  ~Linkedlist()
  {
    printf("Freeing Memory\n");
    this->freeMemory(this->head);
    free(new_node);
  }

  Linkedlist(Linkedlist &source)
  {
    printf("Copying %p to %p\n", &source, this);
    Node *node = source.head;
    while (node)
    {
      this->append(node->value);
      node = node->next;
    }
    this->freeMemory(source.head);
    free(source.new_node);
    source.new_node = nullptr;
    source.head = nullptr;
    source.tail = nullptr;
  }

  Linkedlist &operator=(Linkedlist &source)
  {
    printf("Copying %p to %p\n", &source, this);
    if (&source == this)
    {
      return *this;
    }
    Node *node = source.head;
    while (node)
    {
      this->append(node->value);
      node = node->next;
    }
    this->freeMemory(source.head);
    free(source.new_node);
    source.new_node = nullptr;
    source.head = nullptr;
    source.tail = nullptr;
    return *this;
  }

  Linkedlist(Linkedlist &&source)
  {
    printf("Moving %p to %p\n", &source, this);
    Node *node = source.head;
    while (node)
    {
      this->append(node->value);
      node = node->next;
    }
    this->freeMemory(source.head);
    free(source.new_node);
    source.new_node = nullptr;
    source.head = nullptr;
    source.tail = nullptr;
  }

  Linkedlist &operator=(Linkedlist &&source)
  {
    printf("Moving %p to %p\n", &source, this);
    if (&source == this)
    {
      return *this;
    }
    Node *node = source.head;
    while (node)
    {
      this->append(node->value);
      node = node->next;
    }
    this->freeMemory(source.head);
    free(source.new_node);
    source.new_node = nullptr;
    source.head = nullptr;
    source.tail = nullptr;
    return *this;
  }

  Node *head = nullptr;
  Node *tail = nullptr;
  int num_entries = 0;

  void append(std::string const &value);
  std::string pop();
  void remove(std::string &&target);
  void printList() const;
  int getSize() const;
};

#endif