#include <iostream>
#include <stack>

using namespace std;

class List
{
private:
	struct Node
	{
		int data;
		Node *next;

		Node(int value) : data(value), next(NULL){};
	}*head;
public:
	List() { head = NULL; }
	void push_at_beginning(int data)
	{
		Node *new_node = new Node(data);
		if(!head)
		{
			head = new_node;
		}
		else
		{
			new_node->next = head;
			head = new_node;
		}
	}
	void print_list()
	{
		Node *temp = head;
		while(temp)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
};

List merge_stacks_into_list(stack<int> my_stack1, stack<int> my_stack2)
{
	List result;
	while(!my_stack1.empty() && !my_stack2.empty())
	{
		if(my_stack1.top() < my_stack2.top())
		{
			result.push_at_beginning(my_stack2.top());
			my_stack2.pop();
		}
		else
		{
			result.push_at_beginning(my_stack1.top());
			my_stack1.pop();
		}		
	}
	if(my_stack1.empty())
	{
		result.push_at_beginning(my_stack2.top());
		my_stack2.pop();
	}
	if(my_stack2.empty())
	{
		result.push_at_beginning(my_stack1.top());
		my_stack1.pop();
	}
	return result;
}

int main(int argc, char const *argv[])
{
	stack<int> my_stack1;
	my_stack1.push(1);
	my_stack1.push(3);
	my_stack1.push(5);
	my_stack1.push(7);
	stack<int> my_stack2;
	my_stack2.push(2);
	my_stack2.push(4);
	my_stack2.push(6);
	my_stack2.push(8);
	List merged = merge_stacks_into_list(my_stack1, my_stack2);
	merged.print_list();
	return 0;
}