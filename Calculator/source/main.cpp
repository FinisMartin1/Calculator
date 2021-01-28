#include <iostream>
#include <string>
#include <stack>
#include "Tree.h"
using namespace std;
/* CPSC2380
* Department of Computer Science, UALR
* Project 2
* Student Name: Finis Martin
* Student UALR ID (last four digits): 2180
* Project Descriptions: This project takes an equation and evaluates it using and exprestion tree.
*it also show it in inorder and postorder form
* Project Due Date: 4/19/2019
* Project Revised Date: 4/15/2018, 4/19/2018
*/
bool is_digit(string str)
{

	if (!str.compare("(")
		|| !str.compare(")")
		|| !str.compare("+")
		|| !str.compare("/")
		|| !str.compare("-")
		|| !str.compare("*"))
		return false;
	else return true;

}

bool has_precendence(string stk, string str)
{
	if (stk == "+" || stk == "-")
		if (str == "*" || str == "/")
			return false;
	return true;
}

string InfixToPostfix(char* str)
{
	stack<string> equation_r, equation;
	stack<string> operator_stack;
	stack<string> postfix_eq;
	string current_token;

	char* token;

	token = strtok(str, " ");
	//Push all tokens onto stack
	while (token != NULL)
	{
		//	cout << "Token = " << token << endl;
		equation_r.push(token);
		token = strtok(NULL, " ");
	}

	//Reverse stack of tokens
	while (!equation_r.empty())
	{
		//cout << "Equation reversal = " << equation_r.top() << endl;
		equation.push(equation_r.top());
		equation_r.pop();
	}

	//Algorithm
	while (!equation.empty())
	{
		//cout << "Algorithm token = " << equation.top() << endl;
		current_token = equation.top();
		equation.pop();
		if (!current_token.compare("("))
			operator_stack.push(current_token);
		else if (is_digit(current_token))
		{
			//cout << "Is digit" << endl;
			postfix_eq.push(current_token);
		}
		else if (!current_token.compare(")"))
		{
			string temp_token;
			temp_token = operator_stack.top();
			operator_stack.pop();

			while (temp_token.compare("("))
			{
				postfix_eq.push(temp_token);
				temp_token = operator_stack.top();
				operator_stack.pop();
			}
		}
		else
		{
			if (operator_stack.empty() || operator_stack.top() == "(")
				operator_stack.push(current_token);
			else
			{
				while (!operator_stack.empty() && has_precendence(operator_stack.top(), current_token))
				{
					string temp_token;
					temp_token = operator_stack.top();
					operator_stack.pop();
					postfix_eq.push(temp_token);
				}
				operator_stack.push(current_token);
			}
		}
	}

	//Clear operator stack
	while (!operator_stack.empty())
	{
		postfix_eq.push(operator_stack.top());
		operator_stack.pop();
	}

	//cout << "Your equation is..." << endl;

	//Reverse again
	while (!postfix_eq.empty())
	{
		equation_r.push(postfix_eq.top());
		postfix_eq.pop();
	}

	string postfix_string = "";
	while (!equation_r.empty())
	{
		equation.push(equation_r.top());
		//cout << equation_r.top() << " ";
		postfix_string = postfix_string + equation_r.top() + " ";
		equation_r.pop();
	}
	//cout << endl << postfix_string << endl;
	//cout << endl;

	while (!equation.empty())
		equation.pop();

	while (!equation_r.empty())
		equation_r.pop();

	while (!operator_stack.empty())
		operator_stack.pop();

	while (!postfix_eq.empty())
		postfix_eq.pop();

	return postfix_string;
}

int main()
{

	string s;
	cout << "Type your equation: ";
	getline(cin, s);
	cout << endl;
	int n = s.length();

	char* str = new char[n];
	strcpy(str, s.c_str());
	s = InfixToPostfix(str);
	cout << "PostFix: " << s << endl;
	Tree equation(s);

	cout << "The sum is: " << equation.evaluate(equation.getTop()) << endl;
	cout << "inorder: " << endl;
	equation.inorder(equation.getTop());
	cout << endl;
	cout << "post-order: " << endl;
	equation.postorder(equation.getTop());
	system("pause");




}
