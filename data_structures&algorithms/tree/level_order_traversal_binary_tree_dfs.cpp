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

int find_height(Node *root)
{
	if(root == NULL)
		return 0;

	int in_left = find_height(root->left);
	int in_right = find_height(root->right);

	return 1 + ((in_left > in_right) ? in_left : in_right);
}

void print_level(Node *root, int level)
{
	if(root == NULL)
		return;

	if(level == 1)
	{
		std::cout << root->data << " ";
		return;
	}

	print_level(root->left, level - 1);
	print_level(root->right, level - 1);
}

void level_order_dfs(Node *root)
{
	int levels = find_height(root);
	for(int i = 1; i <= levels; ++i)
	{
		print_level(root, i);
		std::cout << std::endl;
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

	level_order_dfs(a);
	
	return 0;
}
