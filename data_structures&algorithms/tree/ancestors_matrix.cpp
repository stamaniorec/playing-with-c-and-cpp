#include <iostream>

template <typename T>
struct TreeNode
{
	T data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(T data) : data(data), left(NULL), right(NULL) {};
};

// Given a binary tree, return a matrix where
// mat(i, j) is 1 when i is an ancestor of j.

template <typename T>
int num_nodes_in_tree(TreeNode<T>* root)
{
	if(!root) return 0;
	return num_nodes_in_tree(root->left) + num_nodes_in_tree(root->right) + 1;
}

template <typename T>
void populate_matrix(TreeNode<T>* root, bool* matrix, int matrix_size)
{
	if(!root) return;

	if(root->left)
	{
		populate_matrix(root->left, matrix, matrix_size);

		matrix[root->data * matrix_size + root->left->data] = 1;
		for(int i = 0; i < matrix_size; ++i)
		{
			if(matrix[root->left->data * matrix_size + i] == 1)
				matrix[root->data * matrix_size + i] = 1;
		}
	}

	if(root->right)
	{
		populate_matrix(root->right, matrix, matrix_size);
	
		matrix[root->data * matrix_size + root->right->data] = 1;
		for(int i = 0; i < matrix_size; ++i)
		{
			if(matrix[root->right->data * matrix_size + i] == 1)
				matrix[root->data * matrix_size + i] = 1;
		}
	}
}

// I decided to "simulate" a matrix by using an array instead because
// dynamic memory allocation is tricky enough on its own,
// let alone dealing with a matrix with a pointer to a pointer and all that...

template <typename T>
bool* solve(TreeNode<T>* root)
{
	int nodes_in_tree = num_nodes_in_tree(root);
	bool* matrix = new bool[nodes_in_tree * nodes_in_tree];

	populate_matrix(root, matrix, nodes_in_tree);

	for(int i = 0; i < nodes_in_tree; ++i)
	{
		for(int j = 0; j < nodes_in_tree; ++j)
		{
			std::cout << matrix[i*nodes_in_tree + j] << " ";
		}
		std::cout << std::endl;
	}

	return matrix;
} 

int main(int argc, char const *argv[])
{
	// 	     0
	// 	    / \
	//     1   2
	//    / \   \
	//   3   4   7
	//        \  /
	//         5 8
	//          \
	//           6
	TreeNode<int> n0(0);
	TreeNode<int> n1(1);
	TreeNode<int> n2(2);
	TreeNode<int> n3(3);
	TreeNode<int> n4(4);
	TreeNode<int> n5(5);
	TreeNode<int> n6(6);
	TreeNode<int> n7(7);
	TreeNode<int> n8(8);
	n0.left = &n1;
	n0.right = &n2;
	n1.left = &n3;
	n1.right = &n4;
	n4.right = &n5;
	n5.right = &n6;
	n2.right = &n7;
	n7.left = &n8;

	bool* matrix = solve(&n0);
	delete[] matrix;

	return 0;
}