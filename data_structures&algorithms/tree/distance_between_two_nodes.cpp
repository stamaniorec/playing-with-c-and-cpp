#include <iostream>
#include <algorithm>

template <typename T>
struct TreeNode
{
	T data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(T data) : data(data), left(NULL), right(NULL) {};
};

// Given a binary tree, calculate the distance between any two given nodes.

#define NOT_FOUND 1000000

template <typename T>
int distance_from_root_to_node(TreeNode<T>* root, TreeNode<T>* node)
{
	if(!root) return NOT_FOUND;
	if(root == node) return 0;

	int left_dist = distance_from_root_to_node(root->left, node);
	int right_dist = distance_from_root_to_node(root->right, node);

	if(left_dist == NOT_FOUND && right_dist == NOT_FOUND)
		return NOT_FOUND;
	else
		return std::min(left_dist, right_dist) + 1;
}

template <typename T>
TreeNode<T>* LCA(TreeNode<T>* root, TreeNode<T>* a, TreeNode<T>* b)
{
	if(!root) return NULL;
	if(root == a || root == b) return root;

	TreeNode<T>* in_left = LCA(root->left, a, b);
	TreeNode<T>* in_right = LCA(root->right, a, b);

	if(in_left && in_right) return root;
	if(in_left) return in_left;
	if(in_right) return in_right;

	return NULL;
}

template <typename T>
int distance_between_two_nodes(TreeNode<T>* root, TreeNode<T>* a, TreeNode<T>* b)
{
	int distance_from_root_to_a = distance_from_root_to_node(root, a);
	int distance_from_root_to_b = distance_from_root_to_node(root, b);
	if(distance_from_root_to_a == NOT_FOUND || distance_from_root_to_b == NOT_FOUND) return NOT_FOUND;

	return
		distance_from_root_to_a +
		distance_from_root_to_b -
		2 * distance_from_root_to_node(root, LCA(root, a, b));
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

	std::cout << "--- --- --- Testing distance from root to node --- --- ---" << std::endl;
	std::cout << distance_from_root_to_node(&n1, &n1) << std::endl; // 0
	std::cout << distance_from_root_to_node(&n1, &n2) << std::endl; // 1
	std::cout << distance_from_root_to_node(&n1, &n3) << std::endl; // 1
	std::cout << distance_from_root_to_node(&n1, &n4) << std::endl; // 2
	std::cout << distance_from_root_to_node(&n1, &n5) << std::endl; // 2

	TreeNode<int> does_not_exist(-123);
	std::cout << distance_from_root_to_node(&n1, &does_not_exist) << std::endl; // not found

	std::cout << "--- --- --- Testing LCA --- --- ---" << std::endl;
	std::cout << LCA(&n1, &n1, &n2)->data << std::endl; // 100
	std::cout << LCA(&n1, &n2, &n1)->data << std::endl; // 100
	std::cout << LCA(&n1, &n1, &n5)->data << std::endl; // 100
	std::cout << LCA(&n1, &n4, &n5)->data << std::endl; // 200
	std::cout << LCA(&n1, &n5, &n2)->data << std::endl; // 200
	std::cout << LCA(&n1, &n4, &n3)->data << std::endl; // 100

	std::cout << "Testing distance between two nodes --- --- ---" << std::endl;
	std::cout << distance_between_two_nodes(&n1, &n1, &n1) << std::endl; // 0
	std::cout << distance_between_two_nodes(&n1, &n2, &n1) << std::endl; // 1
	std::cout << distance_between_two_nodes(&n1, &n1, &n5) << std::endl; // 2
	std::cout << distance_between_two_nodes(&n1, &n4, &n5) << std::endl; // 2
	std::cout << distance_between_two_nodes(&n1, &n5, &n2) << std::endl; // 1
	std::cout << distance_between_two_nodes(&n1, &n4, &n3) << std::endl; // 3
	std::cout << distance_between_two_nodes(&n1, &n4, &does_not_exist) << std::endl; // not found

	return 0;
}