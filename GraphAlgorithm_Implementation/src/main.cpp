#include "graph_data_structure.h"
#include <string>
#include <vector>

int main() {  
  Node node1 = Node("A");
  Node node2 = Node("B");
  Node node3 = Node("C");
  Node node4 = Node("D");
  std::vector<Node> nodes = {node1, node2, node3, node4};

  // Initializing Graph and connecting Nodes
  Graph mygraph = Graph(nodes);
  mygraph.connectEdges(node1, node2);
  mygraph.connectEdges(node2, node3);
  mygraph.connectEdges(node3, node1);
  mygraph.connectEdges(node1, node4);

  // Displaying the Visiting Order
  std::vector<std::string> visited = BFS(node2);
  printArrayElements(visited);
}
