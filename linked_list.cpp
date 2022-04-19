#include <string>
#include <iostream>

using std::string;
using std::cout;

class Node{
	public:
		Node(string value_): value(value_){}
		string value;
		Node* next = nullptr;
};


class Linkedlist{
	public:
		Node* head = nullptr;
		Node* tail = nullptr;
		int num_entries = 0;
		 
		void append(string value){
			Node* new_node = new Node(value);
			if (this->head == nullptr){
				this->head = new_node;
				this->tail = this->head;
				this->num_entries ++;
				return;
			}
			
			this->tail->next = new_node;
			this->tail = this->tail->next;
			this->num_entries ++;
			return;
		}
		
		string pop(){
			Node* old_head = this->head;
			this->head = this->head->next;
			this-> num_entries --;
			return old_head->value;
		}
		
		void remove(string target){
			Node* node = this->head;
			this-> num_entries --;
			while (node){
				if (node->next->value == target){
					node->next = node->next->next;
					return;
					}
				node = node -> next;
			}
		}
		
		void printList(){
			Node * node = this->head;
		
			while (node){
				cout << node->value << "\n";
				node = node->next;
			}
		}
		
		int getSize(){
			return this->num_entries;
		}

};


int main(){
	Linkedlist ll = Linkedlist();
	ll.append("ambrose");
	ll.append("riinu");
	ll.append("dom");
	ll.append("batman");
	ll.append("bruce wayne");
	ll.append("catwoman");
	
	
	ll.remove("batman");
	ll.remove("catwoman");

	cout << ll.getSize() << "\n";
	ll.printList();
}
