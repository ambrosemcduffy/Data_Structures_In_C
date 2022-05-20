#ifndef HEADER_GRAPH_H
#define HEADER_GRAPH_H

#include <string>
#include <vector>

class Node {
public:
  Node(std::string const &value) : value_(value) {}
  void addChild(Node &nodeValue);
  std::string getValue() const;
  std::vector<Node> getChildren() const;

private:
  std::string value_;
  std::vector<Node> children;
};

class Graph {
public:
  Graph(std::vector<Node> const &nodes_) : nodes(nodes_) {}
  void connectEdges(Node &to_node, Node &from_node);

private:
  std::vector<Node> nodes;
  bool ifInArray(Node &queryNode) const;
};

bool const ifInArray(Node &queryNode, std::vector<std::string> &visited);
void const printArrayElements(std::vector<std::string> &array);
std::vector<std::string> const BFS(Node &startNode);

#endif