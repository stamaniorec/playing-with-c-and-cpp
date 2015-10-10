#include <iostream>
#include <vector>

using namespace std;

class Heap
{
private:
	vector<int> heap;
public:
	int parent(int index)
	{
		return (index - 1) / 2;
	}

	void add(int value)
	{
		heap.push_back(value);
		int max = heap.size() - 1;
		while(value > heap[parent(max)])
		{
			int temp = heap[max];
			heap[max] = heap[parent(max)];
			heap[parent(max)] = temp;
			max = parent(max);	
		}
	}

	void extract()
	{
		heap[0] = heap[heap.size() - 1];
		int greatest;
		int current = 0;
		while(1)
		{
			if(heap[2*current + 1] > heap[2*current + 2])
				greatest = 2*current + 1;
			else
				greatest = 2*current + 2;
			if(heap[current] < heap[greatest])
			{
				int temp = heap[current];
				heap[current] = heap[greatest];
				heap[greatest] = temp;
				current = greatest;
				heap.pop_back();
			}
			else
			{
				return;
			}
		}
	}
	void print()
	{
		for(unsigned int i = 0; i < heap.size(); i++)
		{
			cout << heap[i] << " ";
		}
		cout << endl;
	}
};

int main(int argc, char const *argv[])
{
	Heap heap;
	heap.add(1);
	heap.add(2);
	heap.add(4);
	heap.add(5);
	heap.add(7);
	heap.add(9);
	heap.print();
	heap.extract();
	heap.print();
	heap.extract();
	heap.print();	
	return 0;
}
