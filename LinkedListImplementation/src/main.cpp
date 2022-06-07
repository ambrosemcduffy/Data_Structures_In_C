#include "linked_list.h"
#include <iostream>

int main()
{
  Linkedlist ll;

  // Appending Values to list
  ll.append("ambrose");
  ll.append("riinu");
  ll.append("dom");
  ll.append("batman");
  ll.append("bruce wayne");
  ll.append("catwoman");
  ll.append("Peter Parker");

  // removing a few values
  ll.remove("batman");
  ll.remove("catwoman");
  ll.pop();

  Linkedlist ll2(ll);
  Linkedlist ll3(std::move(ll2));
  ll3.printList();
  return 0;
}