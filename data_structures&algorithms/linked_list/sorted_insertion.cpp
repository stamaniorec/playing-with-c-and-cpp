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
}

void SortedInsert(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    if(head == NULL)
    {
        head = new_node;
        head->prev = NULL;
        head->next = NULL;
        return;
    }
    Node *tail = head;
    while(tail->next != NULL)
    {
        tail = tail->next;
    }
    if(data < head->data)
    {
        head->prev = new_node;
        new_node->next = head;
        new_node->prev = NULL;
        head = new_node;
    }
    else if(data > tail->data)
    {
        tail->next = new_node;
        new_node->prev = tail;
        new_node->next = NULL;
        tail = new_node;
    }
    else
    {
        Node *temp = head;
        while(temp->data < data)
        {
            temp = temp->next;
        }
        Node *prev_node = temp->prev;
        prev_node->next = new_node;
        new_node->next = temp;
        new_node->prev = prev_node;
        temp->prev = new_node;
    }
}

int main(int argc, char const *argv[])
{
	SortedInsert(4);
	print_list();
	return 0;
}