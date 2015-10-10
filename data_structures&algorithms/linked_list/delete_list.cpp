#include <iostream>

using namespace std;

class List
{
private:
	struct Node
	{
		int data;
		Node *next;
	}*head;
public:
	List()
	{
		head = NULL;
	}
	void delete_list()
	{
		Node *temp = NULL;
		while(head)
		{
			temp = head->next;
			delete head;
			head = temp;
		}
	}
	void push(int number)
	{
		Node *new_node = new Node;
		new_node->data = number;
		if ( head == NULL )
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
		if ( head == NULL )
		{
			cout << "Empty list." << endl;
		}
		else
		{
			Node *temp = head;
			while ( temp )
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
		}
	}

};


int main(int argc, char const *argv[])
{
	List list;
	list.print_list();
	list.push(3);
	list.push(2);
	list.push(1);
	list.print_list();
	list.delete_list();
	list.print_list();
	return 0;
}