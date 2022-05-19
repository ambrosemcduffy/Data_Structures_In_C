#include <iostream>
#include <string>

#include "binaryTree.h"
#include "searchAlgorithm.h"

void whichSearchAlgorithm(Tree &tree) {
  std::string searchAlgorithm;
  std::cout << "Which search algorithm you want for the tree search?? \n";
  std::cin >> searchAlgorithm;

  if (searchAlgorithm == "bfs") {
    BFS(tree.getRoot());
  } else {
    DFS(tree.getRoot());
  }
}

int main() {

  // Initializing Tree
  Tree mytree = Tree();
  mytree.insert("Ambrose");
  mytree.insert("Riinu");
  mytree.insert("Dom");
  mytree.insert("Batman");
  mytree.insert("Bill Maher");
  mytree.insert("CNN");
  mytree.insert("Sunset Park");
  mytree.insert("Baby Boomer");

  whichSearchAlgorithm(mytree);
}
