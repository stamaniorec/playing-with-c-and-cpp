#include <iostream>

using namespace std;

class List
{
private:
	struct Node
	{
		int data;
		Node *p;
	}*head;
public:
	List()
	{
		head = NULL;
	}
	void push(int number)
	{
		Node *new_node = new Node;
		new_node->data = number;
		new_node->p = head;
		head = new_node;
	}
	void print()
	{
		Node *temp = head;
		while(temp != NULL)
		{
			cout << temp->data;
			temp = temp->p;
		}
		cout << endl;
	}
	int get_length()
	{
		int length = 0;
		Node *temp = head;
		while(temp != NULL)
		{
			length++;
			temp = temp->p;
		}
		return length;
	}
	int get_nth_from_end(int desired)
	{
		int length = get_length();	// 3 
		int n = length - desired;	// 1
		int a = 1;
		Node *temp = head;
		while ( temp != NULL )
		{
			if(a == n)
			{
				return temp->data;
			}
			temp = temp->p;
			a++;
		}
	}
};

int main(int argc, char const *argv[])
{
	List list; 
	list.push(3);
	list.push(2);
	list.push(1);
	list.print();

	int n = 2;
	cout << list.get_nth_from_end(n) << endl;

	return 0;
}