#include <iostream>

class BinaryTree
{
private:
	struct Node
	{
		int data;
		Node *left;
		Node *right;

		Node(int data1) : data(data1), left(NULL), right(NULL) {};
	};

	Node *root;

	void inorder_traversal_private(Node *root)
	{
		if(root)
		{
			inorder_traversal_private(root->left);
			std::cout << root->data << " ";
			inorder_traversal_private(root->right);
		}
		else
		{
			return;
		}
	}

	Node* add_private(Node *root, int data)
	{
		if(!root)
		{
			Node *new_node = new Node(data);
			root = new_node;
			return root;
		}
		if(root->data < data)
		{
			root->right = add_private(root->right, data);
		}
		else if(root->data > data)
		{
			root->left = add_private(root->left, data);
		}
	}

	bool search_private(Node *root, int data)
	{
		if(!root)
			return false;
		if(root->data == data)
		{
			return true;
		}
		else if(root->data < data)
		{
			search_private(root->right, data);
		}
		else
		{
			search_private(root->left, data);
		}
	}
public:
	BinaryTree() : root(NULL) {};

	void inorder_traversal()
	{
		inorder_traversal_private(root);
		std::cout << std::endl;
	}

	void add(int data)
	{
		root = add_private(root, data);
	}

	bool contains(int data)
	{
		return search_private(root, data);
	}

};

int main(int argc, char const *argv[])
{
	BinaryTree tree;
	tree.add(5);
	tree.add(3);
	tree.add(10);
	tree.inorder_traversal();
	if(tree.contains(5))
		std::cout << "The tree contains the value 5.\n";
	else
		std::cout << "The tree does not contain the value 5.\n";
	if(tree.contains(4))
		std::cout << "The tree contains the value 4.\n";
	else
		std::cout << "The tree does not contain the value 4.\n";
	return 0;
}