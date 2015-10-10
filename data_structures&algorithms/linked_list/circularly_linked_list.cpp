#include <iostream>

using namespace std;

class List
{
private:
	struct Node
	{
		int data;
		Node *prev;
		Node *next;

		Node(int data1) : data(data1), prev(0), next(0){};
	}*head;
public:
	List()
	{
		head = new Node(0);
		head->prev = head->next = head;
	}
	void push_front(int data)
	{
		Node *new_node = new Node(data);
		Node *front = head->next;
		head->next = new_node;
		new_node->prev = head;
		front->prev = new_node;
		new_node->next = front;
	}
	void push_back(int data)
	{
		Node *new_node = new Node(data);
		Node *back = head->prev;
		head->prev = new_node;
		new_node->next = head;
		back->next = new_node;
		new_node->prev = back;
	}
	bool is_empty()
	{
		return head == head->next;
	}
	int front()
	{
		if(is_empty())
		{
			cout << "Empty list." << endl;
		}
		return head->next->data;
	}
	int back()
	{
		if(is_empty())
		{
			cout << "Empty list." << endl;
		}
		return head->prev->data;
	}
	void print()
	{
		Node *current = head->next;
		Node *start = head;
		if(current == start)
			cout << "Empty list." << endl;
		while(current != start)
		{
			cout << current->data << " ";
			current = current->next;
		}
	}
	void pop_front()
	{
		Node *front=head->next;
    	Node *new_front=front->next;
 
 	   	head->next=new_front;
   	 	new_front->prev=head;
 
    	delete front;
	}
	void pop_back()
	{
		Node *back = head->prev;
		Node *new_back = back->prev; 
		
		head->prev = new_back;
		new_back->next = head;

		delete back;
	}
};

int main(int argc, char const *argv[])
{
	List list;
	list.print();
	list.push_back(10);
    cout << list.back() << endl;
 
    list.push_back(20);
    cout << list.back() << endl;
 
    list.push_front(-10);
    cout << list.front() << endl;
 
    list.push_front(-20);
    cout << list.front() << endl;

    list.print();
    list.pop_front();
    cout << endl;
    list.print();
    cout << endl;
    list.pop_back();
    list.print();
    cout << endl;
    cout << list.front() << endl;
    cout << list.back() << endl;

    list.push_front(100);
    cout << list.front() << endl;
    list.push_back(-100);
    cout << list.back() << endl;

    list.print();

   	return 0;
}