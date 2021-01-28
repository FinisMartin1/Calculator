#include "Tree.h"
#include <iostream>
using namespace std;

//Tree constructor
Tree::Tree()
{
	top = nullptr;

}
//Tree deconstuctor
Tree::~Tree()
{


}
// Tree convertion constuctor, takes in a string that is postfixed
Tree::Tree(string data)
{
	string tempStr;
	//loops trough data
	for (int i = 0; i < data.length(); i++)
	{
		// if data[i] does not equal 32 or space then add data[i] to tempStr
		if (data[i] != 32)
		{
			tempStr = tempStr + data[i];

		}
		else
		{
			// else if data[i] equal space then insert tempStr in the tree and clear tempStr
			insert(tempStr);
			tempStr = "";
		}
	}


}
// push nodes to be saved for later use
void Tree::pushNode(Node* temp)
{
	// if the top node equals node then make the top node equal temp. else temp1 equals temp node
	// temp1 next while equal top and top will equal temp1
	if (top != NULL)
	{
		TempNode* temp1 = new TempNode(temp);
		temp1->next = top;
		top = temp1;

	}
	else
	{

		top = new TempNode(temp);
	}

}
//pops the the stored nodes off note: if the syntax is correct then this fuction should work
Node* Tree::popNode()
{
	//pop the top and makes its next equal top
	Node* temp;
	temp = top->node;
	top = top->next;
	return temp;

}
// inserts Nodes into tree
void Tree::insert(string val)
{
	// if the val equals +,-,*,/ then Node temp equals new node val it calls popNode and
	// stores the value into the right and calls it again and stores it in the left.
	//it then calls pushNode to push to put temp node as the new root.
	if (val == "+" || val == "-" || val == "*" || val == "/")
	{
		Node* temp = new Node(val);
		temp->right = popNode();
		temp->left = popNode();
		pushNode(temp);
	}
	else
	{
		//else temp node equals new node and call push node
		Node* temp = new Node(val);
		pushNode(temp);
	}
}
//gets the root of the tree
Node* Tree::getTop()
{

	return top->node;
}
//evaluates tree
int Tree::evaluate(Node* temp)
{
	int sum = 0;
	//if the left and right node equal null then it must be an value
	if (temp->left == NULL && temp->right == NULL)
	{
		//if so then it will loop trough each digit and caluate by taking the sum*10 + (val[1]- '0')
		for (int i = 0; i < temp->val.length(); i++)
		{
			int digit = temp->val[i] - '0';
			sum = sum * 10 + digit;
		}
		// return the sum
		return sum;
	}
	// if its not an value then it an operand which in that case it will use recursion to find the sum
	char op = temp->val[0];
	switch (op)
	{
	case '+':
		sum = evaluate(temp->left) + evaluate(temp->right);
		break;
	case '-':
		sum = evaluate(temp->left) - evaluate(temp->right);
		break;
	case '*':
		sum = evaluate(temp->left) * evaluate(temp->right);
		break;

	case '/':
		sum = evaluate(temp->left) / evaluate(temp->right);
		break;




	}
	// returns sum when done
	return sum;
}

//displays the tree in inorder, uses recursion
void Tree::inorder(Node* temp)
{
	if (temp != NULL)
	{
		inorder(temp->left);
		cout << temp->val << endl;
		inorder(temp->right);
	}
}

//displays the tree in postorder uses recusion
void Tree::postorder(Node* temp)
{
	if (temp != NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		cout << temp->val << endl;
	}
}
