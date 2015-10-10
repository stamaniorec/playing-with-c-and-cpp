#include <iostream>
#include <queue>

//     1
//    / 
//   2  
//  / \ 
// 3   5

//      1
//     / 
//    2  
//   / \ 
//  3   5
// / \
//4   6

struct TreeNode
{
	int data;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int data) : data(data), left(NULL), right(NULL) {};
};

int with_dfs(TreeNode *root)
{
	if(!root)
		return 0;

	int leaves_in_left = with_dfs(root->left);
	int leaves_in_right = with_dfs(root->right);

	// If leaf
	if(!leaves_in_left && !leaves_in_right)
		return 1;

	return leaves_in_left + leaves_in_right;
}

int with_bfs(TreeNode *root)
{
	int num_leaves = 0;

	std::queue<TreeNode*> q;
	q.push(root);

	while(!q.empty())
	{
		TreeNode *cur = q.front();
		q.pop();

		// If leaf
		if(!cur->left && !cur->right)
			++num_leaves;

		if(cur->left)
			q.push(cur->left);
		if(cur->right)
			q.push(cur->right);
	}

	return num_leaves;
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

	std::cout << "num leaves " << with_dfs(a) << std::endl; // 2
	std::cout << "num leaves " << with_bfs(a) << std::endl; // 2

	TreeNode *e = new TreeNode(4);
	c->left = e;
	TreeNode *f = new TreeNode(6);
	c->right = f;

	std::cout << "num leaves " << with_dfs(a) << std::endl; // 3
	std::cout << "num leaves " << with_bfs(a) << std::endl; // 3
		
	return 0;
}