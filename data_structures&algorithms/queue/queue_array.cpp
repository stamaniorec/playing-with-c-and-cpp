#include <iostream>

using namespace std;

const int queue_length = 100;

class Queue
{
private:
	int array[queue_length];
	int head;
	int tail;
public:
	Queue() : head(-1), tail(-1)
	{
		for(int i = 0; i < queue_length; i++)
		{
			array[i] = 0;
		}
	}

	bool is_empty()
	{
		return head == -1 && tail == -1;
	}

	void enqueue(int data)
	{
		if(tail == queue_length - 1)
		{
			cout << "Full queue." << endl;
			return;
		}
		else if(is_empty())
		{
			head++;
		}
		array[++tail] = data;
	}

	void dequeue()
	{
		if(is_empty())
		{
			cout << "Empty queue. Cannot dequeue." << endl;
		}
		else if(head == tail)
		{
			head = tail = -1;
		}
		else
		{
			head++;
		}
	}

	void print()
	{
		if(is_empty())
		{
			cout << "Empty queue." << endl;
			return;
		}
		for(int i = head; i <= tail; i++)
		{
			cout << array[i] << " ";
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