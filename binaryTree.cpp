#include <string>
#include <iostream>
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

		

		void setValue(string newValue) { this->value = newValue; }

		void setLeft(Node* newValue) { this->left = newValue; }

		void setRight(Node* newValue) { this->right = newValue; }

		string getValue() const { return this-> value; }

		Node* getLeft() const { return this->left; }

		Node* getRight() const { return this->right; }

		bool hasLeft() { return this->left != nullptr; }

		bool hasRight() { return this->right != nullptr; }
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
	deque<Node*> queue = {root};
	
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


void DFS(Node* node){
    if (node){
        std::cout << node->getValue() << "\n";
        DFS(node->getLeft());
        DFS(node->getRight());
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

    std::string algo;
    std::cout << "Which search algorithm you want for the tree search?? \n"; 
    std::cin >> algo;
    std::cout << "\n";

    if (algo == "bfs"){
        BFS(mytree.getRoot());
    }
    else{
        DFS(mytree.getRoot());
    }
	
	
}
