#include <iostream>

struct TreeNode
{
	int data;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int data) : data(data), left(NULL), right(NULL) {};
};

bool found = false;

// Standard function to return the smallest element of a given tree
TreeNode* find_min(TreeNode *root)
{
	if(root->left)
		find_min(root->left);
	else
		return root;
}

// Given a node's value and a BST, represented with a pointer to its root element, 
// Returns the given node's inorder successor. 
// The function assumes the node exists and the BST contains no duplicates.
// Also, this solution is mine so it's far from perfect or optimized.
TreeNode* inorder_successor(TreeNode *root, int value)
{
	if(!root)
		return NULL; 

	if(root->data == value)
	{
		// If the node has a right subtree
		if(root->right)
		{
			// The inorder successor is going to be the smallest element in it
			found = true;
			return find_min(root->right);
		}
		// Otherwise return it
		else
		{
			return root;
		}
	}

	// Search for the node in the left subtree
	TreeNode *left = inorder_successor(root->left, value);

	// If you found it there
	if(left)
	{
		// If its inorder successor has not yet been found
		if(!found)
		{
			// The root is definitely bigger than the left child
			// so it is the inorder successor
			found = true;
			return root;
		}
		// Otherwise return the inorder successor you have found
		else
		{
			return left;
		}
	}


	// Search for the node in the right subtree
	TreeNode *right = inorder_successor(root->right, value);

	// If you found it there
	if(right)
	{
		// Simply return it, because you can't do anything with it
		return right;
	}

	// std::cout << "No inorder successor" << std::endl;
	return NULL;
}

// This is the actual solution
TreeNode* inorder_success(TreeNode *root, int K)
{
	TreeNode *successor = NULL;
	TreeNode *current  = root;

	if(!root)
		return NULL;
	
	// Iteratively search in the BST
	while(current->data != K)
	{
		// If "root" is greater than K, search in the left subtree and update the successor
		if(current->data > K)
		{
			successor = current;
			current= current->left;
		}
		// Otherwise, search in the right subtree and DON'T update the successor
		else
			current = current->right;
	}

	// If we have found the node and it has a right subtree
	if(current && current->right)
	{
		// The inorder successor is the smallest element in the right subtree
		successor = find_min(current->right);
	}
	
	return successor;
}

TreeNode* find_max(TreeNode *root)
{
	if(root->right)
		find_max(root->root);
	else
		return root;
}

// Here is the predecessor, it's nearly the same
TreeNode* inorder_predecessor(TreeNode *root, int K)
{
	TreeNode *predecessor = NULL;
	TreeNode *current  = root;

	if(!root)
		return NULL;
	
	while(current->data != K)
	{
		if(current->data > K)
			current= current->left;
		else
		{
			predecessor = current;
			current = current->right;
		}
	}

	if(current && current->left)
	{
		predecessor = find_max(current->left);
	}
	
	return predecessor;
}

int main(int argc, char const *argv[])
{
	//     --10--
	//    /      \
	//   6       14
	//  / \     /  \
	// 4   8   12  15
	TreeNode *a = new TreeNode(10);
	TreeNode *b = new TreeNode(6);
	TreeNode *c = new TreeNode(14);
	TreeNode *d = new TreeNode(4);
	TreeNode *e = new TreeNode(8);
	TreeNode *f = new TreeNode(12);
	TreeNode *g = new TreeNode(15);

	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->left = f;
	c->right = g;

	int n;
	std::cin >> n;
	std::cout << (inorder_successor(a, n))->data << std::endl;
	std::cout << (inorder_success(a, n))->data << std::endl;

	// If there's no successor/predecessor, the second function returns NULL and I try
	// to dereference it, so that's why there's a seg fault

	return 0;
}