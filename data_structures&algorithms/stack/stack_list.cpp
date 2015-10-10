#include <iostream>

using namespace std;

class Stack
{
private:
	struct Node
	{
		int data;
		Node *next;
	}*head;
public:
	Stack()
	{
		head = NULL;
	}

	void push(int number)
	{
		Node *new_node = new Node;
		new_node->data = number;
		if(head == NULL)
		{
			head = new_node;
		}
		else
		{
			new_node->next = head;
			head = new_node;
		}
	}
	
	int pop()
	{
		int temp = head->data;
		Node *temp1 = head;
		head = temp1->next;
		delete temp1;
		return temp;
	}

	int peek()
	{
		return head->data;
	}

	void print_stack()
	{
		Node *temp = head;
		while(temp != NULL)
		{
			cout << temp->data << " --> ";
			temp = temp->next;
		}
		cout << "NULL" << endl;
	}
};

int main(int argc, char const *argv[])
{
	Stack stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	cout << stack.pop() << endl;
	cout << stack.peek() << endl;
	stack.print_stack();
	return 0;
}