#include <iostream>
#include <deque>
#include "searchAlgorithm.h"


void BFS(Node *root) {
  std::deque<Node *> queue = {root};

  while (queue.size() > 0) {

    Node *node = queue.front();
    std::cout << node->getValue() << "\n";

    queue.pop_front();

    if (node->hasLeft()) {
      queue.push_front(node->getLeft());
    }
    if (node->hasRight()) {
      queue.push_front(node->getRight());
    }
  }
}

void DFS(Node *node) {
  if (node) {
    std::cout << node->getValue() << "\n";
    DFS(node->getLeft());
    DFS(node->getRight());
  }
}
