#include <iostream>

using namespace std;

class List
{
private:
	struct Node
	{
		int data;
		Node *p;
	}*head;
public:
	List()
	{
		head = NULL;
	}
	void push(int number)
	{
		Node *new_node = new Node;
		new_node->data = number;
		new_node->p = head;
		head = new_node;
	}
	void print()
	{
		Node *temp = head;
		while(temp != NULL)
		{
			cout << temp->data;
			temp = temp->p;
		}
		cout << endl;
	}
	int get_length()
	{
		int length = 0;
		Node *temp = head;
		while(temp != NULL)
		{
			length++;
			temp = temp->p;
		}
		return length;
	}
	void remove_duplicates()
	{
		Node *temp = head;
		Node *next_node = temp->p;
		while(temp != NULL)
		{
			while(temp->data == next_node->data)
			{
				Node *holder = next_node;
				next_node = next_node->p;
				temp->p = next_node;
				delete holder;
				if ( next_node == NULL )
					return;
			}
			temp = next_node;
			next_node = next_node->p;
		}
	}
};

int main(int argc, char const *argv[])
{
	List list; 
	list.push(3);
	list.push(3);
	list.push(3);
	list.push(2);
	list.push(2);
	list.push(1);
	list.push(1);
	list.push(1);
	list.push(1);
	list.print();

	list.remove_duplicates();
	list.print();

	

	return 0;
}