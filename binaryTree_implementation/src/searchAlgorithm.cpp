#include "searchAlgorithm.h"
#include <deque>
#include <iostream>

void const BFS(Node *root) {
  std::deque<Node *> queue = {root};

  while (queue.size() > 0) {
    Node *node = queue.front();
    std::cout << node->getValue() << "\n";
    Node * temp = node;

    queue.pop_front();

    if (node->hasLeft()) {
      queue.push_front(node->getLeft());
    }
    if (node->hasRight()) {
      queue.push_front(node->getRight());
    }
    delete temp;
  }
}

void const DFS(Node *node) {
  Node *temp = node;
  if (node) {
    std::cout << node->getValue() << "\n";
    DFS(node->getLeft());
    DFS(node->getRight());
  }
  delete temp;
}
