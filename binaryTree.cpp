#include <string>
#include <deque>
#include <iostream>

using std::cout;
using std::deque;
using std::string;


class Node{
	/*
	Node container class for Tree Data Structure
	*/

	private:
				Node* left = nullptr;
				Node* right = nullptr;
				string value;
	
	public:
				Node(string value_):value(value_){}
				
				string getValue(){
					return this-> value;
				}
				
				void setValue(string newValue){
					this->value = newValue;
				}
				
				bool hasLeft(){
					return this->left != nullptr;
				}
				
				bool hasRight(){
					return this->right != nullptr;
				}
				
				void setLeft(Node* newValue){
					this->left = newValue;
				}
				
				void setRight(Node* newValue){
					this->right = newValue;
				}
				
				Node* getLeft(){
					return this->left;
				}
				Node* getRight(){
					return this->right;
				}
};


class Tree{
	private:
		Node* root = nullptr;
	
	public:
		void setRoot(string newValue){
			this->root = new Node(newValue);
			}
		
		Node* getRoot(){
			return this->root;
		}
		
		void insert(string value){
			Node* newNode = new Node(value);
			
			if (this->getRoot() == nullptr){
				this->setRoot(value);
				}
			
			else{
				Node* node = this->getRoot();
				while(true){
					if (node->hasLeft()){
						if (node->hasRight()){
							node = node->getLeft();
						}
						else{
							
							node->setRight(newNode);
							break;
						}
					}
					else{
						node->setLeft(newNode);
						break;
					}
				}
			}
		}

};


void BFS(Node* root){
	deque queue = {root};
	
	while (queue.size() > 0){
	
		Node* node = queue.front();
		cout << node->getValue() << "\n";
	
		queue.pop_front();
		
		if (node->hasLeft()){
			queue.push_front(node->getLeft());
		}
		if (node->hasRight()){
			queue.push_front(node->getRight());
		}
	}
}

int main(){
	
	Node root = Node("ambrose");
	Node left = Node("B");
	Node right = Node("C");
	
	Tree mytree = Tree();
	
	mytree.insert("Ambrose");
	mytree.insert("Riinu");
	mytree.insert("Dom");
	mytree.insert("Batman");
	mytree.insert("Bill Maher");
	mytree.insert("CNN");
	mytree.insert("Sunset Park");
	mytree.insert("Baby Boomer");
	
	BFS(mytree.getRoot());
	
	
}
