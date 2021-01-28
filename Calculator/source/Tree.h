#ifndef TREE_H
#define TREE_H
#include <string>
#include "Node.h"

using namespace std;

class Tree
{

public:

	Tree();
	Tree(string data);
	~Tree();
	Node* popNode();
	void pushNode(Node* temp);
	void insert(string val);
	int evaluate(Node* temp);
	Node* getTop();
	void inorder(Node* temp);
	void postorder(Node* temp);
private:
	TempNode* top;
};






#endif
