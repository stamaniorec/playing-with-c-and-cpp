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

int depth_util(Node *root, int value, int level)
{
	if(root == NULL)
		return 0;

	if(root->data == value)
		return level;

	int in_left = depth_util(root->left, value, level + 1);
	int in_right = depth_util(root->right, value, level + 1);
	
	return in_left ? in_left : in_right;
}

void depth_of(Node *root, int value)
{
	std::cout << "Depth of " << value << ": " << depth_util(root, value, 1) << std::endl;
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

	depth_of(a, 7);
	
	return 0;
}
