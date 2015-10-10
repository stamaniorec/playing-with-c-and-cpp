#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node *p;
};

Node *head = NULL;

void add_to_list(Node **head_ref, int value)
{
	Node *new_node = new Node;
	new_node->data = value;

	if ( head_ref == NULL )
	{
		*head_ref = new_node;
		*head_ref = NULL;
	}
	else
	{
		new_node->p = *head_ref;
		*head_ref = new_node;
	}
}

void print_list(Node *head_ref)
{
	Node *temp = head_ref;
	if ( head_ref == NULL )
	{
		cout << "Empty list" << endl;
		return;
	}
	while ( temp != NULL )
	{
		cout << temp->data;
		temp = temp->p;
	}
} 

void reverse()
{
	Node *current = head;
	Node *previous = NULL;
	Node *next = NULL;

	while ( current != NULL )
	{
        next = current->p;
        current->p = previous;
        previous = current;
        current = next;
    }

    head = previous;
}

int main()
{
	
	add_to_list(&head, 3);
	add_to_list(&head, 2);
	add_to_list(&head, 1);
	print_list(head);
	cout << endl;
	
	reverse();

	print_list(head);

	return 0;
}