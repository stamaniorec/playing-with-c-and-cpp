#include <iostream>

template <typename T>
struct ListNode
{
	T data;
	ListNode* next;

	ListNode(T data) : data(data), next(NULL) {};
};

// Given a linked list, e.g.
// 1 -> 2 -> 3 -> 4 -> 5 -> 6
// Rearrange it in such a way that odd nodes are next to each other
// and even nodes are next to each other.
// 1 -> 3 -> 5 -> 2 -> 4 -> 6

template <typename T>
void rearrange(ListNode<T>** head)
{
	ListNode<T>* odd_nodes_head = NULL;
	ListNode<T>* odd_nodes_tail;
	ListNode<T>* even_nodes_head = NULL;
	ListNode<T>* even_nodes_tail;

	bool odd = true;
	ListNode<T>* cur = *head;
	while(cur)
	{
		ListNode<T>* next = cur->next;

		if(odd)
		{
			if(!odd_nodes_head)
			{
				odd_nodes_head = cur;
				odd_nodes_tail = cur;
			}
			else
			{
				odd_nodes_tail->next = cur;
				odd_nodes_tail = cur;
			}
		}
		else
		{
			if(!even_nodes_head)
			{
				even_nodes_head = cur;
				even_nodes_tail = cur;
			}
			else
			{
				even_nodes_tail->next = cur;
				even_nodes_tail = cur;
			}
		}

		cur = next;
		odd = !odd;
	}

	odd_nodes_tail->next = even_nodes_head;
	even_nodes_tail->next = NULL;

	*head = odd_nodes_head;
}

int main(int argc, char const *argv[])
{
	ListNode<int> n1(1);
	ListNode<int> n2(2);
	ListNode<int> n3(3);
	ListNode<int> n4(4);
	ListNode<int> n5(5);
	ListNode<int> n6(6);
	ListNode<int> n7(7);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	n6.next = &n7;

	ListNode<int>* x = &n1;
	rearrange(&x);

	// Verify output
	ListNode<int>* itr = &n1;
	while(itr)
	{
		std::cout << itr->data << " ";
		itr = itr->next;
	}
	std::cout << std::endl;

	return 0;
}