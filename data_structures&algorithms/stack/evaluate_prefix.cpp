#include <iostream>
#include <string>
#include <stack>

using namespace std;

int operation(char my_operator, int a, int b)
{
	if(my_operator == '+')
	{
		return a + b;
	}
	else if(my_operator == '-')
	{
		return a - b;
	}
	else if(my_operator == '*')
	{
		return a * b;
	}
	else if(my_operator == '/')
	{
		return a / b;
	}
}

// +120,3
// (120 + 3)*4 - 643
// (+120,3)*4 - 643
// *+120,3,4 - 643
// -*+120,3,4,643 
int evaluate_prefix(string expression)
{
	stack<int> my_stack;
	int result = 0;
	int power = 1;
	int operand1, operand2;
	for(int i = expression.length() - 1; i >= 0; i--)
	{
		if(expression[i] >= '0' && expression[i] <= '9')
		{
			result += (expression[i]-'0')*power;
			power *= 10;
		}
		else if(expression[i] == ',')
		{
			my_stack.push(result);
			result = 0;
			power = 1;
		}
		else if(expression[i] == '+' || expression[i] == '-' || 
			expression[i] == '*' || expression[i] == '/')
		{
			if(result)
				my_stack.push(result);
			operand1 = my_stack.top();
			my_stack.pop();
			operand2 = my_stack.top();
			my_stack.pop();
			result = operation(expression[i], operand1, operand2);
			my_stack.push(result);
			result = 0;
		}
	}
	return my_stack.top();
}

int main(int argc, char const *argv[])
{
	string expression;
	cout << "Enter prefix expression: ";
	cin >> expression;

	cout << evaluate_prefix(expression) << endl;

	return 0;
}