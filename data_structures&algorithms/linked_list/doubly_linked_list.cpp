#include <iostream>

using namespace std;

class Node
{
private: 
	int data;
	Node *next;
	Node *prev;
public: 
	Node()
	{
		data = 0;
		next = NULL;
		prev = NULL;
	}

	int get_data() { return data; }
	void set_data(int arg) { data = arg; }

	Node* Next() { return next; }
	Node* Prev() { return prev; }
	void set_next(Node *arg) { next = arg; }
	void set_prev(Node *arg) { prev = arg; }	
};

class List // Doubly linked list
{
private: 
	Node *head;
	Node *tail; // not necessary but if I don't have that then why not just use a singly linked list?
public: 
	List()
	{
		head = NULL;
	}

	void push(int number)
	{
		Node *new_node = new Node;
		new_node->set_data(number);
		if ( head == NULL )
		{
			head = tail = new_node;
		}
		else
		{
			new_node->set_next(head);
			head->set_prev(new_node);
			head = new_node;
		}
	}

	void append(int number)
	{
		Node *new_node = new Node;
		new_node->set_data(number);
		if ( head == NULL )
		{
			head = new_node;
		}
		else
		{
			tail->set_next(new_node);
			new_node->set_prev(tail);
			tail = new_node;
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
				cout << temp->get_data() << " ";
				temp = temp->Next();
			}
		}
	}

	void print_reverse()
	{
		if ( head == NULL )
		{
			cout << "Empty list." << endl;
		}
		else
		{
			Node *temp = tail;
			while ( temp != NULL )
			{
				cout << temp->get_data() << " ";
				temp = temp->Prev();
			}
		}
	}

};

int main(int argc, char const *argv[])
{
	List list;
	list.push(1);
	list.push(2);
	list.push(3);
	list.print_list();
	cout << endl;
	list.print_reverse();
	cout << endl;
	// 3 2 1

	list.append(0);
	list.append(-1);
	list.print_list();
	cout << endl;
	list.print_reverse();
	cout << endl;
	return 0;
}