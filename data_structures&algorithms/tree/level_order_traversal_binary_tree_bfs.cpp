#include <iostream>
#include <queue>

//    3
//  /  \
// 9   20    
//    /  \
//   15    7

struct Node
{
	int data;
	Node *left;
	Node *right;

	Node(int data) : data(data) {};
};

void with_two_queues(Node *root)
{
	std::queue<Node*> this_level;
	std::queue<Node*> next_level;

	this_level.push(root);
	while(!this_level.empty())
	{
		Node *cur = this_level.front();
		this_level.pop();
		std::cout << cur->data << " ";

		if(cur->left) 
			next_level.push(cur->left);
		if(cur->right)
			next_level.push(cur->right);

		if(this_level.empty())
		{
			std::cout << std::endl;
			this_level = next_level;
			
			while(!next_level.empty()) next_level.pop(); // clearing
		}
	}
}

void with_one_queue(Node *root)
{
	std::queue<Node*> q;
	q.push(root);
	int nodes_in_this_level = 1;
	int nodes_in_next_level = 0;
	while(!q.empty())
	{
		Node *cur = q.front();
		q.pop();
		--nodes_in_this_level;
		std::cout << cur->data << " ";

		if(cur->left) 
		{
			q.push(cur->left);
			++nodes_in_next_level;
		}

		if(cur->right)
		{
			q.push(cur->right);
			++nodes_in_next_level;
		}
			

		if(nodes_in_this_level == 0)
		{
			std::cout << std::endl;
			nodes_in_this_level = nodes_in_next_level;
			nodes_in_next_level = 0;
		}
	}
}

int main(int argc, char const *argv[])
{
	Node *a = new Node(3);

	Node *b = new Node(9);
	a->left = b;

	Node *c = new Node(20);
	a->right = c;

	Node *d = new Node(15);
	c->left = d;

	Node *e = new Node(7);
	c->right = e;

	with_two_queues(a);
	with_one_queue(a);
	
	return 0;
}
