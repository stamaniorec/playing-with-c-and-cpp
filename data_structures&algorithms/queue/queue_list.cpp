#include <iostream>

using namespace std;

class Queue
{
private: 
	struct Node
	{
		int data;
		Node *next;

		Node(int value) : data(value), next(NULL){};
	};
	Node *front;
	Node *back;
public:
	Queue() : front(NULL), back(NULL){};
	bool is_empty()
	{
		return front == NULL && back == NULL;
	}
	void enqueue(int value)
	{
		Node *new_node = new Node(value);
		if(is_empty())
		{
			front = back = new_node;
		}
		back->next = new_node;
		back = new_node;
	}
	void dequeue()
	{
		if(is_empty())
		{
			cout << "Empty queue. Cannot dequeue." << endl;
			return;
		}
		else if(front == back)
		{
			Node *temp = front;
			front = back = NULL;
			delete temp;
		}
		else
		{
			Node *temp = front;
			front = front->next;
			delete temp;			
		}

	}
	void print()
	{
		if(is_empty())
		{
			cout << "Empty queue." << endl;
			return;
		}
		Node *current = front;
		while(current)
		{
			cout << current->data << " ";
			current = current->next;
		}
	}
	
};

int main(int argc, char const *argv[])
{
	Queue queue;
	queue.print();
	queue.enqueue(5);
	queue.enqueue(3);
	queue.enqueue(1);
	queue.print();
	cout << endl;
	queue.dequeue();
	queue.dequeue();
	queue.print();
	cout << endl;
	queue.dequeue();
	queue.print();
	return 0;
}