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
			cout << temp->data << " ";
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
	// 4 3 1 2 6 8
	// 4 1 2 6 8

	// 4 3 2 6
	void delete_every_kth_node(int k)
	{
		Node *current = head;
		Node *temp = NULL;
		while(true)
		{
			for (int i = 1; i < k - 1; ++i)
			{
				current = current->p;
			}
			if(!current || !current->p)
				break;
			if(current->p->p)
			{
				temp = current->p;
				current->p = current->p->p;
				delete temp;
				current = current->p;	
			}
			else 
			{	
				delete current->p;
				current->p = NULL;
				break;
			}
			print();
		}
	}
};

int main(int argc, char const *argv[])
{
	List list;
	/*list.push(8);
	list.push(6);
	list.push(2);
	list.push(1);
	list.push(3);
	list.push(4);*/
   	for(int i = 10; i >= 1; i--)
   	{
   		list.push(i);
   	}
   	list.print();
	list.delete_every_kth_node(3);
	list.print();
	return 0;
}