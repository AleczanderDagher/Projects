//--------------------------------------------------------------------
//
//  Lab 6                                          
// 
//  postfix.cpp
//
//--------------------------------------------------------------------

#include<iostream>
#include<cmath>
#include<string>
#include<stack>

using namespace std;

int operators(char op) 
{
	if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^')
		return 1; 
	else
		return 0; 
}

//--------------------------------------------------------------------

int operand(char op)
{
	if (op >= '0' && op <= '9')
		return 1;
	else
		return 0; 
}

//--------------------------------------------------------------------

float operation(double op1, double op2, char o) 
{
	
	if (o == '+')
		return op2 + op1;
	else if (o == '-')
		return op2 - op1;
	else if (o == '*')
		return op2 * op1;
	else if (o == '/')
		return op2 / op1;
	else if (o == '^')
		return pow(op2, op1); 
	else
		return 0; 
}

//--------------------------------------------------------------------

float postfix_evaluation(string postfix) 
{
	double op1, op2;
	stack<float> s;  
	string::iterator it;
	for (it = postfix.begin(); it != postfix.end(); it++) 
	{
		if (operators(*it) != -1) 
		{ 
			op1 = s.top();
			s.pop();
			op2 = s.top();
			s.pop();
			s.push(operation(op1, op2, *it));
		}
		else if (operand(*it) == 1) 
		{
			s.push(*it - '0'); 
		}
	}
	return s.top(); 
}

int main() 
{
	string expression;
	cout << "Enter postfix expression: "; 
	getline(cin, expression);
	cout << "Value of expression = " << postfix_evaluation(expression);
}