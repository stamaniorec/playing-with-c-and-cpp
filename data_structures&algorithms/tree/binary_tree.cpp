#include <iostream>
#include <iomanip> 
#include <queue> // for breadth-first traversal     

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;

	Node(int value) : data(value), left(NULL), right(NULL){};
}*root = NULL;

void insert(int value)
{
	Node *new_node = new Node(value);
	Node *temp = root;

	if(!temp)
	{
		temp = new_node;
		return;
	}

	while(temp)
	{
		if(temp->data < value)
		{
			if(temp->right == NULL)
			{
				temp->right = new_node;
				break;
			}
			else
			{
				temp = temp->right;
			}
		}
		else
		{
			if(temp->left == NULL)
			{
				temp->left = new_node;
				break;
			}
			else
			{
				temp = temp->left;
			}
		}
	}
}

bool search(int value)
{
	Node *temp = root;
	while(temp)
	{
		if(temp->data == value)
			return true;
		if(temp->data < value)
		{
			temp = temp->right;
		}
		else 
		{
			temp = temp->left;
		}
	}
	return false;
}

Node* insert_recursive(Node *root, int value)
{
	Node *new_node = new Node(value);
	if(!root)
	{
		root = new_node;
	}
	else if(root->data <= value)
	{
		root->right = insert_recursive(root->right, value);
	}
	else
	{
		root->left = insert_recursive(root->left, value);
	}
	return root;
}

bool search_recursive(Node *root, int value)
{
	if(!root)
		return 0;
	if(root->data == value)
		return true;
	if(root->data < value)
		search_recursive(root->right, value);
	else
		search_recursive(root->left, value);
}

int number_of_nodes(Node *root)
{
	if(!root)
		return 0;
	return number_of_nodes(root->left) + 1 + number_of_nodes(root->right);
	/*static int result = 0;
	if(root)
	{
		number_of_nodes(root->left);
		number_of_nodes(root->right);
		return ++result;
	}*/
}

int maximum_depth(Node *root)
{
	if(!root)
		return 0;
	int length_of_left_subtree = maximum_depth(root->left);
	int length_of_right_subtree = maximum_depth(root->right);
	if(length_of_left_subtree > length_of_right_subtree)
		return length_of_left_subtree + 1;
	else
		return length_of_right_subtree + 1;
}

void inorder_traversal(Node *root)
{
	if(root)
	{
		inorder_traversal(root->left);
		cout << root->data << endl;
		inorder_traversal(root->right);
	}
}

void preorder_traversal(Node *root)
{
	if(root)
	{
		cout << root->data << endl;
		preorder_traversal(root->left);
		preorder_traversal(root->right);
	}
}

int minimum_element_iterative(Node *root)
{

	if(!root)
		return -1;
	while(root->left)
	{
		root = root->left;
	}
	return root->data;
}

int minimum_element_recursive(Node *root)
{
	if(!root)
		return -1;
	if(root->left)
		minimum_element_recursive(root->left);
	else
		return root->data;
}

int lowest_common_ancestor(Node *root, int value1, int value2)
{
	if((root->data >= value1) && (root->data < value2))
		return root->data;
	if(root->data > value1)
	{
		lowest_common_ancestor(root->left, value1, value2);
	}
	else
	{
		lowest_common_ancestor(root->right, value1, value2);
	}
}

bool is_BST(Node *root)
{
	queue<Node*> my_queue;
	if(!root)
	{
		return false;
	}
	my_queue.push(root);
	while(!my_queue.empty())
	{
		Node *temp = my_queue.front();
		my_queue.pop();
		
		if(temp->left && temp->right)
		{
			if((temp->data < temp->left->data) || (temp->data >= temp->right->data))
			{
				return false;
			}	
		}
		
		if(temp->left)
		{
			my_queue.push(temp->left);
		}
		if(temp->right)
		{
			my_queue.push(temp->right);
		}
	}
	return true;
}

/*
		50
	25		 100
10	  35 ;75	500


// 50 25 10 35 100 75 500
*/

Node* get_successor(Node *root)
{
	while(root->right)
	{
		root = root->right;
	}
	return root;
}

Node* remove(Node *root, int value)
{
	if(!root)
		return NULL;
	Node *temp = NULL;
	if(root->data == value)
	{
		if(!root->left)
		{
			temp = root->right;
			delete root;
			return temp;
		}
		else if(!root->right)
		{
			temp = root->left;
			delete root;
			return temp;
		}
		else
		{
			Node *successor = get_successor(root->left);
          	root->data = successor->data;
          	remove(root->left, successor->data);
		}
	}
	else if(root->data < value)
	{
		root->right = remove(root->right, value);
	} 
	else
	{
		root->left = remove(root->left, value);
	}
}

void destroy_tree(Node *root)
{
	if(!root)
		return;
	destroy_tree(root->left);
	destroy_tree(root->right);
	delete root;
}

int main(int argc, char const *argv[])
{
	root = insert_recursive(root, 50);
	root = insert_recursive(root, 100);
	cout << search_recursive(root, 1000) << " " << search_recursive(root, 50) << endl;
	cout << search(500) << " " << search(50) << endl;
	insert(500);
	insert(75);
	insert(25);
	insert(10);
	insert(35);
	cout << search(500) << endl;
	cout << "number of nodes: " << number_of_nodes(root) << endl;
	cout << "maximum depth: " << maximum_depth(root) << endl;
	cout << "inorder traversal: " << endl;
	inorder_traversal(root);
	cout << "preorder traversal: " << endl;
	preorder_traversal(root);
	cout << "minimum element: ";
	cout << minimum_element_iterative(root) << endl;
	cout << "minimum element recursive: ";
	cout << minimum_element_recursive(root) << endl;
	cout << "lowest common ancestor of 75 and 500 is: ";
	cout << lowest_common_ancestor(root, 75, 500) << endl;
	cout << "is tree bst? : " << is_BST(root) << endl;
	remove(root, 50);
	preorder_traversal(root);
	//destroy_tree(root);
	remove(root, 100);
	remove(root, 500);
	remove(root, 75);
	remove(root, 25);
	remove(root, 10);
	remove(root, 35);
	cout << "The tree now has: " << number_of_nodes(root) << " nodes. : )" << endl;
	preorder_traversal(root);
	return 0;
}