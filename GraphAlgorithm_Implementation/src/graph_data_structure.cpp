#include "graph_data_structure.h"
#include <deque>
#include <iostream>
#include <string>
#include <vector>

void Node::addChild(Node &nodeValue) { this->children.push_back(nodeValue); }
std::string Node::getValue() const { return this->value_; }
std::vector<Node> Node::getChildren() const { return this->children; }

void Graph::connectEdges(Node &to_node, Node &from_node) {
  if (this->ifInArray(to_node) or this->ifInArray(from_node)) {
    to_node.addChild(from_node);
    from_node.addChild(to_node);
  }
}

bool Graph::ifInArray(Node &queryNode) const {
  for (Node node : this->nodes) {
    if (queryNode.getValue() == node.getValue()) {
      return true;
    }
  }
  return false;
}

bool const ifInArray(Node &queryNode, std::vector<std::string> &visited) {
  for (auto node_ : visited) {
    if (queryNode.getValue() == node_) {
      return false;
    }
  }
  return true;
}

void const printArrayElements(std::vector<std::string> &array) {
  for (std::string i : array) {
    std::cout << i << "\n";
  }
}

std::vector<std::string> const BFS(Node &startNode) {
  std::deque<Node> queue = {startNode};
  std::vector<std::string> visited;

  while (queue.size() > 0) {
    Node node = queue.front();
    queue.pop_front();
    for (Node child : node.getChildren()) {
      if (ifInArray(node, visited)) {
        visited.push_back(child.getValue());
        queue.push_back(child);
      }
    }
  }
  return visited;
}
