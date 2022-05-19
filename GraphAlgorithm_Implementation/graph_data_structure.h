#ifndef HEADER_GRAPH_H
#define HEADER_GRAPH_H

#include <string>
#include <vector>

class Node {
public:
  Node(std::string value) : value_(value) {}
  void addChild(Node &nodeValue);
  std::string getValue();
  std::vector<Node> getChildren();

private:
  std::string value_;
  std::vector<Node> children;
};

class Graph {
public:
  Graph(std::vector<Node> nodes_) : nodes(nodes_) {}
  void connectEdges(Node &to_node, Node &from_node);

private:
  std::vector<Node> nodes;
  bool ifInArray(Node queryNode);
};

bool ifInArray(Node &queryNode, std::vector<std::string> &visited);
void printArrayElements(std::vector<std::string> array);
std::vector<std::string> BFS(Node startNode);

#endif