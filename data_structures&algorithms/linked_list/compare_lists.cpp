#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node *p;
};

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

bool compare_list(Node *head1, Node *head2)
{
	Node *temp1 = head1;
	Node *temp2 = head2;
	while ( temp1 != NULL )
	{
		if ( temp2 == NULL )
			return false;
		if ( temp1->data != temp2->data )
		{
			return false;
		}
		temp1 = temp1->p;
		temp2 = temp2->p;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	Node *head1 = NULL;
	Node *head2 = NULL;
	add_to_list(&head1, 3);
	add_to_list(&head1, 2);
	add_to_list(&head1, 1);
	add_to_list(&head1, 0);
	print_list(head1);
	cout << endl;
	//add_to_list(&head2, 3);
	add_to_list(&head2, 2);
	add_to_list(&head2, 1);
	add_to_list(&head2, 0);
	print_list(head2);
	cout << endl;
	cout << compare_list(head1, head2);
	return 0;
}
