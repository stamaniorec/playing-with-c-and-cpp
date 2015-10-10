#include <iostream>

//     1             5 
//    /             /  
//   2     <=>     12   
//  / \           / \  
// 3   5         6   5 

struct TreeNode
{
	int data;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int data) : data(data), left(NULL), right(NULL) {};
};

bool are_structurally_identical(TreeNode *a, TreeNode *b)
{
	if(!a && !b)
		return true;

	// if((a && !b) || (b && !a))
	if(!a || !b)
		return false;
	
	return are_structurally_identical(a->left, b->left) && are_structurally_identical(a->right, b->right);
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

	TreeNode *e = new TreeNode(5);
	TreeNode *f = new TreeNode(12);
	TreeNode *g = new TreeNode(6);
	TreeNode *h = new TreeNode(5);
	e->left = f;
	f->left = g;
	f->right = h;

	TreeNode *i = new TreeNode(5);
	TreeNode *j = new TreeNode(12);
	TreeNode *k = new TreeNode(6);
	TreeNode *l = NULL;
	i->left = j;
	j->left = k;
	j->right = l;

	std::cout << "are structurally identical? " << are_structurally_identical(a, e) << std::endl; // 1
	std::cout << "are structurally identical? " << are_structurally_identical(e, i) << std::endl; // 0

	return 0;
}