#include "searchAlgorithm.h"
#include <deque>
#include <iostream>

void const BFS(Node *root)
{
  /*
    Breadth first Search Algorithm
    this function also deletes temp memory.
    @param root Node container
  */

  std::deque<Node *> queue = {root};

  while (queue.size() > 0)
  {
    Node *node = queue.front();
    std::cout << node->getValue() << "\n";
    queue.pop_front();

    if (node->hasLeft())
    {
      queue.push_front(node->getLeft());
    }
    if (node->hasRight())
    {
      queue.push_front(node->getRight());
    }
  }
}

void const DFS(Node *node)
/*
  Depth first Search Algorithm
  this function also deleted heap memory..
  @param node container
*/
{
  Node *temp = node;
  if (node)
  {
    std::cout << node->getValue() << "\n";
    DFS(node->getLeft());
    DFS(node->getRight());
  }
}
