#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node *prev;
	Node *next;
}*head = NULL;

void push(int number)
{
	Node *new_node = new Node;
	new_node->data = number;
	if ( head == NULL )
	{
		head = new_node;
		head->prev = NULL;
		head->next = NULL;
	}
	else
	{
		new_node->next = head;
		new_node->prev = NULL;
		head->prev = new_node;
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
	cout << endl;
}

/*
1) input list:  NULL 
    return:   NULL
2) Input list:  NULL <-- 2 <--> 4 <--> 6 --> NULL 
    return:  NULL <-- 6 <--> 4 <--> 2 --> NULL
*/

int length_of_list()
{
	Node *temp = head;
	int count = 0;
	while(temp)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

void reverse()
{
	if(head == NULL)
	{
		cout << "Empty list." << endl;
		return;
	}
	Node *current = head;
	Node *temp = NULL;
	while(current)
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}
	head = temp->prev;
}

int main(int argc, char const *argv[])
{
	push(3);
	push(2);
	push(1);
	print_list();
	reverse();	
	print_list();
	return 0;
}