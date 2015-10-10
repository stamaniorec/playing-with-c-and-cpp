#include <iostream>

using namespace std;

struct Node 
{
	int data;
	Node *next;
};

Node *head = NULL;

void insert()
{
	Node *temp = new Node;
	cin >> temp->data;

	if ( head == NULL )
	{
		head = temp;
		head->next = NULL;
	}
	else
	{
		temp->next = head;
		head = temp;
	}
}

void print()
{
	Node *temp = head;
	while ( temp != NULL )
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

void Reverse()
{
    Node *temp = head;
    Node *temp2 = head;
    int number_of_elements = 0;
    while ( temp->next != NULL )
    {
        temp = temp->next;
        number_of_elements++;
    }
    int k = 0;
    while ( k < number_of_elements / 2 )
    {
        temp = head;
        temp2 = head;
        for ( int i = k; i < number_of_elements - k; i++ )
        {
            temp = temp->next;
        }
        for ( int j = 0; j < k; j++ )
        {
            temp2 = temp2->next;
        }
        int holder = temp->data;
        temp->data = temp2->data;
        temp2->data = holder; 
        k++;
    }   
}

int main (int argc, char *argv[])
{
	insert();
	insert();
	insert();
	print();
	cout << endl << endl << endl;
	Reverse();
	print();
	return 0;
}
