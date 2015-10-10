#include <iostream>

//     1        1
//    /          \
//   2     <=>    2
//  / \         /  \
// 3   5        5   3

struct TreeNode
{
	int data;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int data) : data(data), left(NULL), right(NULL) {};
};

// Prints the preorder traversal of a binary tree
void print_preorder_util(TreeNode *root)
{
	if(root)
	{
		std::cout << root->data << " ";
		print_preorder_util(root->left);
		print_preorder_util(root->right);
	}
}

// Wrapper for the function above with check for empty tree and newline at the end
void print_preorder(TreeNode *root)
{
	if(!root)
		std::cout << "Empty tree!" << std::endl;
	else
	{
		print_preorder_util(root);
		std::cout << std::endl;
	}	
}

// Turns the given tree into its mirror image
TreeNode* mirror_inplace(TreeNode *root)
{
	if(!root)
		return NULL;

	// Swap the left and right subtrees
	TreeNode *tmp = root->left;
	root->left = root->right;
	root->right = tmp;

	// Recursively do the same for all subtrees
	mirror_inplace(root->left);
	mirror_inplace(root->right);

	return root;
}

// Create a mirror image of the given tree without modifying it
TreeNode *mirror(TreeNode *root)
{
	if(!root)
		return NULL;

	// Similarly to a postorder traversal, first reverse the children
	// Then asign them the other way around to the new tree
	TreeNode *new_root = new TreeNode(root->data);
	new_root->right = mirror(root->left);
	new_root->left = mirror(root->right);

	return new_root;
}

// Given two trees, returns whether they are mirror images of each other
bool are_mirror_trees(TreeNode *a, TreeNode *b)
{
	if(!a && !b)
		return true;

	// if((a && !b) || (b && !a))
	if(!a || !b) 
		return false;

	if(a->data != b->data)
		return false;
	
	return are_mirror_trees(a->left, b->right) && are_mirror_trees(a->right, b->left);
}

int main(int argc, char const *argv[])
{
	TreeNode *a = new TreeNode(1);
	TreeNode *b = new TreeNode(2);
	TreeNode *c = new TreeNode(3);
	TreeNode *d = new TreeNode(5);
	a->left = b;
	b->left = c;
	b->right = d;

	print_preorder(a);                  // 1 2 3 5
	a = mirror_inplace(a);
	print_preorder(a);                  // 1 2 5 3
	TreeNode *mirror_tree = mirror(a);
	print_preorder(mirror_tree);        // 1 2 3 5

	std::cout << "are mirror trees? " << are_mirror_trees(a, mirror_tree) << std::endl; // 1
	std::cout << "are mirror trees? " << are_mirror_trees(a, a) << std::endl;           // 0

	return 0;
}