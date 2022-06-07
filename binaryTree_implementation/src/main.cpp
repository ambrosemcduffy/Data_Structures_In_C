#include <iostream>
#include <string>

#include "binaryTree.h"
#include "searchAlgorithm.h"

int main()
{
  // Creating out tree
  Tree mytree;

  // Appending values
  mytree.insert("Ambrose");
  mytree.insert("Riinu");
  mytree.insert("Dom");

  // Moving our tree members and values to tree2
  //  Tree2 now has exclusive ownership of heap memory
  Tree mytree2(std::move(mytree));

  // Moving our tree members and values to tree2
  //  Tree2 now has exclusive ownership of heap memory
  Tree mytree3 = std::move(mytree2);

  // Copying over our values to tree4
  Tree mytree4 = mytree3;

  // Displaying values using DFS and BFS
  BFS(mytree3.getRoot());
  DFS(mytree4.getRoot());
}
