#include <iostream>

struct ListNode
{
	int data;
	ListNode* arbitrary;
	ListNode* next;

	ListNode(int data) : data(data), arbitrary(NULL), next(NULL) {};
};

// Given a linked list where every node has not only a next pointer, but an arbitrary pointer,
// make it so every node's arbitrary pointer points to the node with the greatest value right of it.

ListNode* solve(ListNode* head)
{
	if(!head) return NULL;

	ListNode* biggest_in_right = solve(head->next);

	if(!biggest_in_right)
		return head;
	else
	{
		head->arbitrary = biggest_in_right;

		if(head->data > biggest_in_right->data)
			return head;
		else
			return biggest_in_right;
	}	
}

int main(int argc, char const *argv[])
{
	ListNode n1(5);
	ListNode n2(10);
	ListNode n3(2);
	ListNode n4(3);

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;

	solve(&n1);

	ListNode* itr = &n1;
	while(itr)
	{
		std::cout << "At node with value " << itr->data << std::endl;
		std::cout << "Biggest in right: ";
		if(itr->arbitrary)
			std::cout << itr->arbitrary->data;
		else
			std::cout << "NULL";
		std::cout << std::endl << std::endl;

		itr = itr->next;
	}
	
	return 0;
}
