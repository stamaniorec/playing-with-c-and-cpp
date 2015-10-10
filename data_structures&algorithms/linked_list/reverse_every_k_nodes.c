#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
	int data;
	struct ListNode *next;
} ListNode;

ListNode* create_list_node(int data)
{
	ListNode *node = malloc(sizeof(ListNode));
	node->data = data;
	node->next = NULL;
	return node;
}

void print_list(ListNode *head)
{
	while(head)
	{
		printf("%d -> ", head->data);
		head = head->next;
	}
	printf("NULL\n");
}

ListNode* reverse_list(ListNode *head)
{
	ListNode *current = head;
	ListNode *prev = NULL;
	while(current)
	{
		ListNode *next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	return prev;
}

// Creates a new node with the given data, 
// and appends it to the end of the list
void add_data_to_list(ListNode **head, int data)
{
	ListNode *new_node = create_list_node(data);
	if(*head == NULL)
		*head = new_node;
	else
	{
		ListNode *current = *head;
		while(current->next)
			current = current->next;
		current->next = new_node;
	}
}

// Returns a new list from the nodes between the two
// given pointers, both included
ListNode* build_sublist(ListNode *start, ListNode *end)
{
	ListNode *head = NULL;
	while(start != end)
	{
		add_data_to_list(&head, start->data);
		start = start->next;
	}
	add_data_to_list(&head, start->data);
	return head;
}

// Appends a ListNode pointer to the end of the list
// In essence, it appends a list to the list. 
void add_node_to_list(ListNode **main_head, ListNode *head)
{
	if(*main_head == NULL)
		*main_head = head;
	else
	{
		ListNode *current = *main_head;
		while(current->next)
			current = current->next;
		current->next = head;
	}
}

ListNode* reverse_every_k_nodes(ListNode *head, int k)
{
	if(head == NULL)
	{
		printf("Empty list!\n");
		return;
	}

	ListNode *result = NULL;

	// Iterate the list
	ListNode *start_of_current_sublist = head;
	while(start_of_current_sublist)
	{
		// Go to the end of the current sublist
		ListNode *end_of_current_sublist = start_of_current_sublist;
		int t = k-1;
		while(end_of_current_sublist && t--)
		{
			end_of_current_sublist = end_of_current_sublist->next;
		}

		// If the current sublist has a length of k
		if(end_of_current_sublist)
		{
			// Build a sublist, reverse it and append it to the final list
			ListNode *cur_sublist = build_sublist(start_of_current_sublist, end_of_current_sublist);
			add_node_to_list(&result, reverse_list(cur_sublist));

			// Move the iterating pointer appropriately
			start_of_current_sublist = end_of_current_sublist->next;
		}
		// Else the end has been reached
		else
		{
			// Append the rest of the list WITHOUT reversing it
			add_node_to_list(&result, start_of_current_sublist);
			start_of_current_sublist = NULL; // exit out of the loop
		}
	}

	return result;
}

// The suggested solution
ListNode* reverse(ListNode *head, int k)
{
    ListNode* current = head;
    ListNode* next = NULL;
    ListNode* prev = NULL;
    int count = 0;   
     
    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k)
    {
       next  = current->next;
       current->next = prev;
       prev = current;
       current = next;
       count++;
    }
     
    /* next is now a pointer to (k+1)th node 
       Recursively call for the list starting from current.
       And make rest of the list as next of first node */
    if(next !=  NULL)
    {  head->next = reverse(next, k); }
 
    /* prev is new head of the input list */
    return prev;
}

// The difference between the suggested solution and my solution in terms of 
// behavior is that if the list's length is not divisible by k
// the last, shorter than k sublist is not reversed in my solution, 
// but it is in the suggested solution
// This change is INTENTIONAL, this way it makes more sense to me.

int main(int argc, char const *argv[])
{
	ListNode *head = create_list_node(5);
	head->next = create_list_node(10);
	head->next->next = create_list_node(15);
	head->next->next->next = create_list_node(20);
	head->next->next->next->next = create_list_node(25);
	head->next->next->next->next->next = create_list_node(30);
	head->next->next->next->next->next->next = create_list_node(35);
	head->next->next->next->next->next->next->next = create_list_node(40);
	head->next->next->next->next->next->next->next->next = create_list_node(45);

	print_list(head);
	print_list(reverse_every_k_nodes(head, 4));

	// ListNode *rev = kAltReverse(head, 3);
	// print_list(rev);
	// print_list(head);
	return 0;
}