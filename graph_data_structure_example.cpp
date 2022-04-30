#include <vector>
#include <iostream>
#include <string>
#include <deque>

using std::vector;
using std::cout;
using std::string;
using std::deque;



class Node {
    public:
        Node(string value):value_(value){}

        void addChild(Node &nodeValue){
            this->children.push_back(nodeValue);
        }

        string getValue(){
            return this->value_;
        }
        vector<Node> getChildren(){
            return this->children;
        }
    private:
        string value_;
        vector<Node> children;
};


class Graph{
    public:
        Graph(vector<Node> nodes_): nodes(nodes_){}
        
        void connectEdges(Node &to_node, Node &from_node){
            if (this->ifInArray(to_node) or this->ifInArray(from_node)){
                to_node.addChild(from_node);
                from_node.addChild(to_node);
            }
        }
        
    private:
        vector<Node> nodes;
        bool ifInArray(Node queryNode){
            for (Node node: this->nodes){
                if (queryNode.getValue() == node.getValue()){
                    return true;
                }
            }
            return false;
        }
};


bool ifInArray(Node &queryNode, vector<string> &visited){
    for (auto node_: visited){
        if (queryNode.getValue() == node_){
            return false;
        }
    }
    return true;
}

void printArrayElements(vector<string> array){
    for (std::string i:array){
        std::cout << i << "\n";
    }
}

vector<string> BFS(Node startNode){
    deque<Node> queue = {startNode};
    vector<string> visited;

    while (queue.size() > 0){
        Node node = queue.front();
        queue.pop_front();
        for (Node child:node.getChildren()){
            if (ifInArray(node, visited)){
                visited.push_back(child.getValue());
                queue.push_back(child);
            }
        }
    }
    return visited;
}

int main(){
    Node node1 = Node("A");
    Node node2 = Node("B");
    Node node3 = Node("C");
    Node node4 = Node("D");

    vector<Node> nodes = {node1, node2, node3, node4};
    Graph mygraph = Graph(nodes);

    mygraph.connectEdges(node1, node2);
    mygraph.connectEdges(node2, node3);
    mygraph.connectEdges(node3, node1);
    mygraph.connectEdges(node1, node4);
    vector<string> visited = BFS(node4);
    printArrayElements(visited);
}

