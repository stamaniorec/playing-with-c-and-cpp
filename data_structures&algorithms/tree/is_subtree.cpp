#include <iostream>

template <typename T>
struct TreeNode
{
	T data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(T data) : data(data), left(NULL), right(NULL) {};
};

// Determine whether a given tree is a subtree of another tree.

template <typename T>
bool are_trees_equal(TreeNode<T>* root1, TreeNode<T>* root2)
{
	if(!root1 && !root2) return true;
	if(!root1 && root2) return false;
	if(root1 && !root2) return false;

	return
		root1->data == root2->data &&
		are_trees_equal(root1->left, root2->left) &&
		are_trees_equal(root1->right, root2->right);
}

template <typename T>
bool is_subtree(TreeNode<T>* subtree_root, TreeNode<T>* tree_root)
{
	if(!subtree_root && !tree_root) return true;
	if(subtree_root && !tree_root) return false;
	if(!subtree_root && tree_root) return false;

	return
		are_trees_equal(subtree_root, tree_root) ||
		is_subtree(subtree_root, tree_root->left) ||
		is_subtree(subtree_root, tree_root->right);
}

int main(int argc, char const *argv[])
{
	// 	    100
	// 	    / \
	//   200  300
	//   /  \
	// 400  500
	TreeNode<int> n1(100);
	TreeNode<int> n2(200);
	TreeNode<int> n3(300);
	TreeNode<int> n4(400);
	TreeNode<int> n5(500);
	n1.left = &n2;
	n1.right = &n3;
	n2.left = &n4;
	n2.right = &n5;
	
	// 	    200
	// 	    / \
	//   400  500
	TreeNode<int> n6(200);
	TreeNode<int> n7(400);
	TreeNode<int> n8(500);
	n6.left = &n7;
	n6.right = &n8;

	std::cout << is_subtree(&n6, &n1) << std::endl; // true

	// 	    200
	// 	    / \
	//   300  500
	TreeNode<int> n9(200);
	TreeNode<int> n10(300);
	TreeNode<int> n11(500);
	n9.left = &n10;
	n9.right = &n11;
	std::cout << is_subtree(&n9, &n1) << std::endl; // false - different data

	// 	    200
	// 	    /
	//   400
	//   /
	// 500
	TreeNode<int> n12(200);
	TreeNode<int> n13(400);
	TreeNode<int> n14(500);
	n12.left = &n13;
	n13.left = &n14;
	std::cout << is_subtree(&n12, &n1) << std::endl; // false - different structure

	return 0;
}