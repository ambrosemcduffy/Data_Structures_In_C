#include "linked_list.h"
#include <iostream>

void useObject(Linkedlist obj) {
  std::cout << "using object " << &obj << std::endl;
}

int main() {
  Linkedlist ll;

  // Appending Values to list
  ll.append("ambrose");
  ll.append("Dom");
  ll.append("Riinu");

  Linkedlist ll2 = ll;
  Linkedlist ll3 = ll2;

  useObject(std::move(ll3));

  return 0;
}
