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

Node* lca(Node *root, int a, int b)
{
	if(!root)
		return NULL;

	if(root->data == a || root->data == b)
		return root;

	Node *in_left = lca(root->left, a, b);
	Node *in_right = lca(root->right, a, b);

	if(in_left && in_right)
		return root;

	return !in_left ? in_right : in_left;
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

	Node *result = lca(a, b->data, e->data);
	std::cout << result->data << std::endl;
	
	
	return 0;
}
