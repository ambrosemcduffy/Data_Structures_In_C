#include "binaryTree.h"
#include <string>
#include <deque>

using std::string;

// Implementation of Setters for Node
void Node::setValue(std::string &&newValue) { this->value = newValue; }
void Node::setLeft(Node *&newValue) { this->left = newValue; }
void Node::setRight(Node *&newValue) { this->right = newValue; }

// Implementation of Getters for Node
std::string Node::getValue() const { return this->value; }
Node *Node::getLeft() const { return this->left; }
Node *Node::getRight() const { return this->right; }

bool Node::hasLeft() const { return this->left != nullptr; }
bool Node::hasRight() const { return this->right != nullptr; }

// Implementing Tree Methods.

// Setters for Tree
void Tree::setRoot(Node *newValue) { this->root = newValue; }
Node *Tree::getRoot() const { return this->root; }

void const Tree::deleteMemory(Node *node)
/*
  Depth first Search delete Algorithm
  this function also deleted heap memory..
  @param node container
*/
{
  Node *temp = node;
  if (node)
  {
    deleteMemory(node->getLeft());
    deleteMemory(node->getRight());
  }
  delete temp;
}

void const Tree::copyValues(Node *source)
{
  /*
    Breadth first Search Algorithm
    this function also deletes temp memory.
    @param root Node container
  */

  std::deque<Node *> queue = {source};

  while (queue.size() > 0)
  {
    Node *node = queue.front();
    this->insert(node->getValue());
    queue.pop_front();

    if (node->hasLeft())
    {
      queue.push_front(node->getLeft());
    }
    if (node->hasRight())
    {
      queue.push_front(node->getRight());
    }
  }
}

// Insert Method
void Tree::insert(std::string &&value)
{
  Node *newNode = new Node(value);

  if (this->getRoot() == nullptr)
  {
    this->setRoot(newNode);
  }

  else
  {
    Node *node = this->getRoot();

    while (true)
    {
      if (node->hasLeft())
      {
        if (node->hasRight())
        {
          node = node->getLeft();
        }

        else
        {
          node->setRight(newNode);
          break;
        }
      }

      else
      {
        node->setLeft(newNode);
        break;
      }
    }
  }
}
