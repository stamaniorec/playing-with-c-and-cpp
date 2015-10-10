#include <iostream>

struct LinkedListNode
{
	int data;
	LinkedListNode *next;
	LinkedListNode(int data) : data(data), next(NULL) {};
};

void print_linked_list(LinkedListNode *head)
{
	while(head)
	{
		std::cout << head->data << " --> ";
		head = head->next;
	}
	std::cout << " NULL" << std::endl;
}

// Splits a given linked list into two parts.
// If it has an odd number of elements, the extra element goes to the first list.
// Since a function can't return two values, the pointers to the first and the second halves
// are passed as pointers to pointers argumens to the function.
void split_list(LinkedListNode *head, LinkedListNode **first_half, LinkedListNode **second_half)
{
	if(!head)
		std::cout << "Empty list, cannot be split." << std::endl;
	else if(!head->next)
		std::cout << "Only one item in the list, cannot be split." << std::endl;
	else
	{
		// Iterate the list with a slow and a fast pointer
		// When the fast pointer finishes the traversal, 
		// the slow pointer is in the middle
		LinkedListNode *slow = head;
		LinkedListNode *fast = head->next;
		while(fast && fast->next)
		{
			slow = slow->next;
			fast = (fast->next->next) ? fast->next->next : NULL;
		}

		*first_half = head;
		*second_half = slow->next;
		slow->next = NULL; // Don't forget to "cut" the first half from the second half
	}
}

LinkedListNode* merge_sorted_lists(LinkedListNode *a, LinkedListNode *b)
{
	LinkedListNode *res = NULL;
	if(!a) return b;
	if(!b) return a;
	if(a->data < b->data)
	{
		res = a;
		res->next = merge_sorted_lists(a->next, b);
	}
	else
	{
		res = b;
		res->next = merge_sorted_lists(a, b->next);
	}
	return res;
}

void merge_sort(LinkedListNode **head)
{
	if(*head == NULL || (*head)->next == NULL)
		return;

	LinkedListNode *first_half;
	LinkedListNode *second_half;
	split_list(*head, &first_half, &second_half);
	
	merge_sort(&first_half);
	merge_sort(&second_half);
	
	*head = merge_sorted_lists(first_half, second_half);
}

int main(int argc, char const *argv[])
{
	LinkedListNode *a = new LinkedListNode(15);
	LinkedListNode *b = new LinkedListNode(7);
	a->next = b;
	LinkedListNode *c = new LinkedListNode(6);
	b->next = c;
	LinkedListNode *d = new LinkedListNode(5);
	c->next = d;
	LinkedListNode *e = new LinkedListNode(3);
	d->next = e;
	LinkedListNode *f = new LinkedListNode(1);
	e->next = f;
	LinkedListNode *g = new LinkedListNode(-1);
	f->next = g;
	LinkedListNode *h = new LinkedListNode(-3);
	g->next = h;

	merge_sort(&a);
	print_linked_list(a);

	return 0;
}