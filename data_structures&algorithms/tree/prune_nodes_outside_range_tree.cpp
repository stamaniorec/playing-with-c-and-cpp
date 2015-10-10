#include <iostream>
#include <queue>

struct TreeNode
{
	int data;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int data) : data(data), left(NULL), right(NULL) {};
};

void print_levelorder(TreeNode *root)
{
	if(!root)
	{
		std::cout << "The tree is empty!" << std::endl;
		return;
	}

	std::queue<TreeNode*> q;
	q.push(root);
	int nodes_in_cur_level = 1;
	int nodes_in_next_level = 0;
	while(!q.empty())
	{
		TreeNode *cur = q.front();
		q.pop();

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
			
		--nodes_in_cur_level;
		if(!nodes_in_cur_level)
		{
			std::cout << std::endl;
			nodes_in_cur_level = nodes_in_next_level;
			nodes_in_next_level = 0;
		}
	}
}

// Given a pointer to the root of a BST, and a range represented with a minimum and maximum value
// Deletes all nodes outside the range and 
// Returns a pointer to the new tree (don't worry, everything happens in-place :) )
TreeNode* prune_nodes_out_of_range(TreeNode *root, int min, int max)
{
	if(!root)
		return NULL;

	// If we remove the root, what happens to the children?
	// This is a hard question to deal with so we process the children first
	// => We use a Postorder traversal of the tree
	root->left = prune_nodes_out_of_range(root->left, min, max);
	root->right = prune_nodes_out_of_range(root->right, min, max);

	// If the current node is smaller than the given range
	if(root->data < min)
	{
		// Then all nodes in its left subtree are also going to be smaller because this is a BST

		TreeNode *right = root->right;
		delete root;
		return right;
	}
	// Else if the current node is bigger than the given range
	else if(root->data > max)
	{
		// Then all nodes in its right subtree are also going to be bigger because this is a BST

		TreeNode *left = root->left;
		delete root;
		return left; 
	}

	return root;
}

int main(int argc, char const *argv[])
{
	// Given tree: 
 	//     --30--
	//    /      \ 
	//   20      40
	//  /  \    /  \
	// 15  25  37  45

	TreeNode *a = new TreeNode(30);
	TreeNode *b = new TreeNode(20);
	TreeNode *c = new TreeNode(15);
	TreeNode *d = new TreeNode(25);
	TreeNode *e = new TreeNode(40);
	TreeNode *f = new TreeNode(37);
	TreeNode *g = new TreeNode(45);

	a->left = b;
	a->right = e;
	b->left = c;
	b->right = d;
	e->left = f;
	e->right = g;
	
	print_levelorder(prune_nodes_out_of_range(a, 22, 40));

	// Range 22-40

	// Result tree: 
	//   30
	//  /  \
	// 25  40
	//    /
	//   37

	return 0;
}