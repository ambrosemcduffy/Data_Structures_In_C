#include "linked_list.h"
#include <iostream>

int main() {
  Linkedlist ll = Linkedlist();

  // Appending Values to list
  ll.append("ambrose");
  ll.append("riinu");
  ll.append("dom");
  ll.append("batman");
  ll.append("bruce wayne");
  ll.append("catwoman");
  
  //removing a few values
  ll.remove("batman");
  ll.remove("catwoman");

  std::cout << ll.getSize() << "\n";
  ll.printList();
}