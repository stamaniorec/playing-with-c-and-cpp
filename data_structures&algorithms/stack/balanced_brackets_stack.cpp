#include <iostream>
#include <string>

using namespace std;

class Stack
{
private:
	struct Node
	{
		char data;
		Node *next;
	}*top_;
public:
	Stack()
	{
		top_ = NULL;
	}
	void push(char n)
	{
		Node *new_node = new Node;
		new_node->data = n;
		if(!top_)
		{
			top_ = new_node;
			top_->next = NULL;
		}
		else
		{
			new_node->next = top_;
			top_ = new_node;
		}
	}
	char pop()
	{
		char holder;
		if(top_)
		{
			Node *temp = top_;
			holder = temp->data;
			top_ = top_->next;
			delete temp;
		}
		return holder;
	}
	bool is_empty()
	{
		if(!top_)
			return true;
		return false;
	}
	char top()
	{
		return top_->data;
	}
};

bool check_brackets(string my_string)
{
	Stack stack;
	for(int i = 0; i < my_string.size(); i++)
	{
		if(my_string[i] == '(' || my_string[i] == '[' || my_string[i] == '{')
		{
			stack.push(my_string[i]);
		}
		else if(my_string[i] == ')')
		{
			if(!stack.is_empty() && stack.top() == '(')
				stack.pop();
			else
				return false;
		}
		else if(my_string[i] == ']')
		{
			if(!stack.is_empty() && stack.top() == '[')
				stack.pop();
			else
				return false;
		}
		else if(my_string[i] == '}')
		{
			if(!stack.is_empty() && stack.top() == '{')
				stack.pop();
			else
				return false;
		}
	}
	return stack.is_empty();
}

int main(int argc, char const *argv[])
{
	string my_string;

	cout << "Enter string: ";
	cin >> my_string;

	cout << check_brackets(my_string) << endl;

	return 0;
}