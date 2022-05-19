#include "linked_list.h"
#include <iostream>
#include <string>

void Linkedlist::append(std::string value) {
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
  Node *old_head = this->head;
  this->head = this->head->next;
  this->num_entries--;
  return old_head->value;
}

void Linkedlist::remove(std::string target) {
  Node *node = this->head;
  this->num_entries--;
  while (node) {
    if (node->next->value == target) {
      node->next = node->next->next;
      return;
    }
    node = node->next;
  }
}

void Linkedlist::printList() {
  Node *node = this->head;

  while (node) {
    std::cout << node->value << "\n";
    node = node->next;
  }
}

int Linkedlist::getSize() { return this->num_entries; }