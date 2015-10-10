#include <iostream>

using namespace std;

class Node
{
	private:
		int data;
		Node *p;
	public:
		Node()
		{
			data = 0;
			p = NULL;
		}

		Node( int number )
		{
			data = number;
			p = NULL;
		}
	
		int get_data() { return data; }
		Node* Next() { return p; }
		void set_next(Node* arg) { p = arg; }
};

class List
{
	private:
		Node *head;
	public:
		List()
		{
			head = NULL;
		}
	
		void append(int number)
		{
			Node *temp = head;
			Node *new_node = new Node(number);
			if ( head == NULL )
			{
				head = new_node;
			}
			else
			{
				while ( temp->Next() != NULL )
				{
					temp = temp->Next();
				}
				temp->set_next(new_node);
			}
		}

		void print()
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
					cout << temp->get_data() << " --> ";
					temp = temp->Next();
				}
				cout << "NULL" << endl;
			}
		}

		int has_loop()
		{
			if(head == NULL)
				return -1;
			Node *slow = head;
			Node *fast = head;
			while(slow && fast && fast->Next())
			{
				slow = slow->Next();
				fast = fast->Next()->Next();
				if(slow == fast)
					return 1;
			}
			return 0;
		}

};

int main()
{
	List list;
	list.append(5);
	list.append(10);
	list.print();
	cout << list.has_loop() << endl;
	return 0;
}
