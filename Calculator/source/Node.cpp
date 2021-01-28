#include "Node.h"

using namespace std;
//Node consturctor
Node::Node()
{


}
//Node converstion contructor
Node::Node(string val)
{
	this->val = val;
	left = nullptr;
	right = nullptr;

}

Node::~Node()
{


}
//TempNode contuctor
TempNode::TempNode()
{

}
// TempNode deconctuctor
TempNode::~TempNode()
{


}
// TempNode converstion contuctor Note: This is used to store nodes for later use
TempNode::TempNode(Node* node)
{
	this->node = node;
	next = nullptr;
}
