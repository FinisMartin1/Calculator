#ifndef NODE_H
#define NODE_H
#include <string>
using namespace std;

class Node
{
	friend class Tree;
	friend class TempNode;
public:
	Node();
	~Node();
	Node(string val);
private:
	string val;
	Node* left;
	Node* right;
};

class TempNode
{
	friend class Tree;
	friend class Node;

public:
	TempNode();
	~TempNode();
	TempNode(Node* node);
private:
	Node* node;
	TempNode* next;


};
#endif
