#include "linked_list.h"
#include <iostream>
#include <string>

void Linkedlist::append(std::string const &value) {
  Node *new_node = new Node(value);
  if (this->head == nullptr) {
    this->head = new_node;
    this->tail = this->head;
    this->num_entries++;
    return;
  }

  this->tail->next = new_node;
  this->tail = this->tail->next;
  this->num_entries++;
  return;
}

std::string Linkedlist::pop() {
  std::string popedValue= this->head->value;
  Node *temp = this->head;
  this->head = this->head->next;
  this->num_entries--;
  delete temp;
  return popedValue;
}

void Linkedlist::remove(std::string &&target) {
  Node *node = this->head;
  this->num_entries--;
  while (node) {
    if (node->next->value == target) {
      Node *temp = node->next;
      node->next = node->next->next;
      delete temp;
      return;
    }
    node = node->next;
  }
}

void const Linkedlist::freeMemory(Node *node){
    while (node)
    {
      Node *temp = node;
      node = node->next;
      delete temp;
    }
}

void Linkedlist::printList() const {
  Node *node = this->head;

  while (node) {
    std::cout << node->value << "\n";
    Node *temp = node;
    node = node->next;
  }
}

int Linkedlist::getSize() const { return this->num_entries; }