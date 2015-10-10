#include <iostream>
#include <stdio.h>

using namespace std;

struct node
{
	int data;
	node *p;
};

node *head = NULL;

void add_to_beginning()
{
	node *temp = new node;
	cin >> temp->data;

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

void add_to_end()
{
	node *temp1, *temp2;

	temp1 = new node;
	cin >> temp1->data;

	temp2 = head;

	if ( head == NULL )
	{
		head = temp1;
		head->p = NULL;
	}
	else
	{
		while (temp2->p != NULL )
		{
			temp2 = temp2->p;
		}

		temp1->p = NULL;
		temp2->p = temp1;
	}
}

void display_list()  
{  
  node *cur_ptr;  
  
  cur_ptr=head;  
  
  if(cur_ptr==NULL)  
  {  
     printf("\nList is Empty");  
  }  
  else  
  {  
      printf("\nElements in the List: ");  
      
      while(cur_ptr!=NULL)  
      {  
          printf(" %d ",cur_ptr->data);  
          cur_ptr=cur_ptr->p;  
      }  
      printf("\n");  
  }  
}

int length()
{
	node *temp = head;
	int counter = 0;

	while ( temp != NULL )
	{
		temp = temp->p;
		counter++;
	}

	return counter;
}

void insert_at()
{
	int index;
	
	cout << "Enter position: ";
	cin >> index;

	node *previous, *current, *temp;

	current = head;

	if ( index > (length() + 1) || index <= 0 )
	{
		cout << "Error\n";
	}
	else
	{
		if ( index == 1 )
		{
			add_to_beginning();
		}
		else
		{
			for ( int i = 1; i < index; i++ )
			{
				previous = current;
				current = current->p;
			}

			temp = new node;
			cin >> temp->data;

			previous->p = temp;
			temp->p = current;
		}
	}
}

void delete_element()
{
	int index;
	
	cout << "Enter index: ";
	cin >> index;
	
	node *temp = head;

	if ( index == 1 )
	{
		head = temp->p;
		delete temp;
	}
	else
	{
		for ( int i = 0; i < index - 2; i++ )
		{
			temp = temp->p;
		}

		node *temp2 = temp->p;
		temp->p = temp2->p;
		delete temp2;
	}
}


int main()
{
	for ( int i = 0; i < 5; i++ )
		add_to_end();

	display_list();

	cout << "The list has " << length() << " elements" << endl;

	insert_at();

	display_list();
	cout << "The list now has " << length() << " elements" << endl;

	delete_element();
	display_list();
	cout << "Now the list has " << length() << " elements" << endl;

	return 0;
}
