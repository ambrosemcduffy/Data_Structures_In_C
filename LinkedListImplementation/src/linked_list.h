#ifndef HEADER_LINKEDLIST_H
#define HEADER_LINKEDLIST_H

#include <string>
#include <stdio.h>


class Node {
public:
  Node(std::string const &value_) : value(value_) {}
  std::string value;
  Node *next = nullptr;
};

class Linkedlist {
private:
Node* new_node = nullptr;
public:
  Linkedlist(){
    printf("Constructor called\n");
    //new_node = (Node *)malloc(sizeof(Node));
  }
  ~Linkedlist(){
    printf("Destructor Called\n");
    //free(new_node);
  }

  void* operator new(size_t size){
    printf("allocating memory of size:%ld\n", size);
    void *new_node = malloc(size);
    return new_node;
  }

  void operator delete(void *new_node){
    printf("deallocating memory\n");
    free(new_node);
    new_node = 0;
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