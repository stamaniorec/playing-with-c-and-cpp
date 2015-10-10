#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool is_digit(char c)
{
	if(c >= '0' && c <= '9')
		return true;
	return false;
}

bool is_delimeter(char c)
{
	if(c == ',')
		return true;
	return false;
}

bool is_operator(char c)
{
	if(c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

int perform_action(char c, int a, int b)
{
	switch(c)
	{
		case '+': 
			return a + b;
		case '-': 
			return a - b;
		case '*': 
			return a * b;
		case '/': 
			return a / b;
	}
}

// 2,3*4,5*+9-     = 17
int evaluate_postfix(string expression)
{
	stack<int> my_stack;
	int result = 0;
	int operator1, operator2;
	int evaluation;
	int temp;
	for(int i = 0; i < expression.length(); i++)
	{
		if(is_digit(expression[i]))
		{
			result = result*10 + expression[i]-'0';
		}
		else if(is_delimeter(expression[i]))
		{
			my_stack.push(result);
			result = 0;
		}
		else if (is_operator(expression[i]))
		{
			if(result)
				my_stack.push(result);
			operator1 = my_stack.top();
			my_stack.pop();
			operator2 = my_stack.top();
			my_stack.pop();
			if(operator1 < operator2)
			{
				temp = operator1;
				operator1 = operator2;
				operator2 = temp;
			}
			evaluation = perform_action(expression[i], operator1, operator2);
			my_stack.push(evaluation);
			result = 0;
		}
	}
	return my_stack.top();
}

int main(int argc, char const *argv[])
{
	string input;
	cout << "Enter postfix expression: ";
	cin >> input;

	cout << "Result: " << evaluate_postfix(input) << endl;

	return 0;
}
