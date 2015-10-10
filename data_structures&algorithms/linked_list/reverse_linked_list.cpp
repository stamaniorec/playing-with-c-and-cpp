#include <iostream>

/*
 * I'm sooo proud of myself. I've been working on linked lists
 * for quite some time now and solving this problem in a matter
 * of minutes was a huge wow for me
 * Have my like, Self!
 * */

using namespace std;

struct Node
{
	int data;
	Node *p;
}*head = NULL;

// an append function would have been better
// but I was too lazy to implement a proper linked list
void add_to_beginning(int number)
{
	Node *temp = new Node;
	temp->data = number;
	
	if ( head == NULL )
	{
		head = temp;
		head->p = NULL;
	}
	else
	{
		temp->p = head;
		head = temp;
	}
}

void print_list()
{
	Node *temp = head;
	
	if ( head == NULL )
	{
		cout << "List is empty." << endl;
	}
	else
	{
		while ( temp != NULL )
		{
			cout << temp->data << " --> ";
			temp = temp->p;
		}
		cout << "NULL" << endl;
	}
}

int length()
{
	Node *temp = head;
	
	int counter = 0;

	while ( temp != NULL )
	{
		counter++;
		temp = temp->p;
	}

	return counter;
}

Node* return_element(int index)
{
	Node *temp = head;
	
	if ( index == 0 )
	{
		return head;
	}
	
	int counter = 1;

	while ( temp != NULL )
	{
		if ( counter == index )
		{
			return temp;
		}

		temp = temp->p;
		counter++;
	}

	return NULL;
}

void reverse_list()
{
	if ( head == NULL )
		return;

	int number_of_elements = length();
	int holder;

	for ( int i = 0; i < number_of_elements / 2; i++ )
	{
		Node *temp1 = return_element(i+1);
		Node *temp2 = return_element(number_of_elements - i);

		holder = temp1->data;
		temp1->data = temp2->data;
		temp2->data = holder;
	}
}

int main()
{
	add_to_beginning(15);
	add_to_beginning(10);
	add_to_beginning(5);
	add_to_beginning(4);
	add_to_beginning(3);
	add_to_beginning(2);

	print_list();
	reverse_list();
	print_list();

	return 0;
}
