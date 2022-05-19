#include "binaryTree.h"
#include <string>

using std::string;

// Implementation of Setters for Node
void Node::setValue(string newValue) { this->value = newValue; }
void Node::setLeft(Node *newValue) { this->left = newValue; }
void Node::setRight(Node *newValue) { this->right = newValue; }

// Implementation of Getters for Node
std::string Node::getValue() { return this->value; }
Node *Node::getLeft() { return this->left; }
Node *Node::getRight() { return this->right; }

bool Node::hasLeft() { return this->left != nullptr; }
bool Node::hasRight() { return this->right != nullptr; }

// Implementing Tree Methods.

// Setters for Tree
void Tree::setRoot(string newValue) { this->root = new Node(newValue); }
Node *Tree::getRoot() { return this->root; }

// Insert Method
void Tree::insert(string value) {
  Node *newNode = new Node(value);

  if (this->getRoot() == nullptr) {
    this->setRoot(value);
  }

  else {
    Node *node = this->getRoot();

    while (true) {
      if (node->hasLeft()) {
        if (node->hasRight()) {
          node = node->getLeft();
        }

        else {
          node->setRight(newNode);
          break;
        }
      }

      else {
        node->setLeft(newNode);
        break;
      }
    }
  }
}