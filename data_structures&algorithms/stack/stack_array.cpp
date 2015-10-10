#include <iostream>

using namespace std;

class Stack
{
private:
	int array[100];
	int top;
public:
	Stack()
	{
		top = -1;
	}

	void push(int number)
	{
		top++;
		array[top] = number;
	}

	int pop()
	{
		top--;
		return array[top];
	}

	int peek()
	{
		return array[top];
	}

	void print_stack()
	{
		for(int i = 0; i <= top; i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;
	}
};

int main(int argc, char const *argv[])
{
	Stack stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.print_stack();
	cout << stack.peek() << endl;
	stack.pop();
	stack.print_stack();
	stack.pop();
	stack.print_stack();
	stack.pop();
	stack.print_stack();
	return 0;
}