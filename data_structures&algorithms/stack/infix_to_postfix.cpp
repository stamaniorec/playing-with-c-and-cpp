#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

// a + b * c - d * e
// a + *bc - d * e 
// +a*bc - d * e 
// +a*bc - *de
// -+a*bc*de

int precedence(char c)
{
	if(c == '(')
		return 0;
	if(c == '+' || c == '-')
		return 1;
	if(c == '*' || c == '/')
		return 2;
}

// (a+b)*c

string convert_to_postfix(string expression)
{
	stringstream result;
	stack<char> my_stack;
	for(int i = 0; i < expression.length(); i++)
	{
		if(expression[i] >= 'a' && expression[i] <= 'z')
		{
			result << expression[i];
		}
		else if(expression[i] == '+' || expression[i] == '-' || 
			expression[i] == '*' || expression[i] == '/')
		{
			while(!my_stack.empty() && precedence(my_stack.top()) >= precedence(expression[i]))
			{
				result << my_stack.top();
				my_stack.pop();
			}
			my_stack.push(expression[i]);
		}
		else if(expression[i] == ')')
		{
			while(!my_stack.empty() && my_stack.top() != '(')
			{
				result << my_stack.top();
				my_stack.pop();
			}
			my_stack.pop();
		}
		else if(expression[i] == '(')
			my_stack.push(expression[i]);
	}
	while(!my_stack.empty())
	{
		result << my_stack.top();
		my_stack.pop();
	}
	return result.str();
}

int main(int argc, char const *argv[])
{
	string expression;
	cout << "Enter infix expression: ";
	cin >> expression;

	cout << convert_to_postfix(expression) << endl;

	return 0;
}