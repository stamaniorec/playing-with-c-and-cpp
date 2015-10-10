#include <iostream>

using namespace std;

/*
 * I did not come up with this algorithm.
 * Nevertheless, it's incredibly simple and yet powerful and elegant.
 * Hat's off to whoever devised it.
 * */

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

/*
1) List A :  1 -> 3 -> 5 -> 6 -> NULL
    List B: 2 -> 4 -> 7 -> NULL
    Expected result: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
*/

// 1 3 5
// 2 4 6

Node* merge_lists ( Node *head1, Node *head2 )
{
	Node *result = NULL;

	if ( head1 == NULL )
		return head2;
	if ( head2 == NULL )
		return head1;

	if ( head1->data <= head2->data )
	{
		result = head1;
		result->p = merge_lists(head1->p, head2);
	}
	else
	{
		result = head2;
		result->p = merge_lists(head1, head2->p);
	}
	return result;
}

int main(int argc, char const *argv[])
{
	Node *head1 = NULL;
	Node *head2 = NULL;
	add_to_list(&head1, 6);
	add_to_list(&head1, 5);
	add_to_list(&head1, 3);
	add_to_list(&head1, 1);
	print_list(head1);
	cout << endl;
	add_to_list(&head2, 7);
	add_to_list(&head2, 4);
	add_to_list(&head2, 2);

	head1 = merge_lists(head1, head2);
	print_list(head1);

	return 0;
}
