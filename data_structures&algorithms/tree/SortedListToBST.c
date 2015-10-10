#include <stdio.h>
#include <stdlib.h>

struct ListNode 
{
	int data;
	struct ListNode *next;
};

struct ListNode* new_list_node(int data)
{
	struct ListNode *node = malloc(sizeof(struct ListNode));
	node->data = data;
	node->next = NULL;
	return node;
}

void print_list(struct ListNode *head)
{
	struct ListNode *cur = head;
	while(cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

struct TreeNode
{
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode* new_tree_node(int data)
{
	struct TreeNode *new_node = malloc(sizeof(struct TreeNode));
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	return new_node;
}

void print_inorder(struct TreeNode *root)
{
	if(root)
	{
		print_inorder(root->left);
		printf("%d ", root->data);
		print_inorder(root->right);
	}
}

/*
inorder traversal skeleton + divide and conquer
we always get the values in a sorted order in inorder traversal
so we do an inorder traversal on the not yet existing tree
and we build it as we go along
and we traverse the list one node at a time 
*/
struct TreeNode* list_to_BST(struct ListNode **head, int start, int end)
{
	if(start > end)
		return NULL;

	int mid = start + (end - start) / 2;

	struct TreeNode *left = list_to_BST(head, start, mid-1);
	struct TreeNode *root = new_tree_node((*head)->data);
	*head = (*head)->next;
	struct TreeNode *right = list_to_BST(head, mid+1, end);	
	
	root->left = left;
	root->right = right;

	return root;
}

/*
We traverse from the bottom, and once we reach a node which matches one of the two nodes, we pass it up to its parent. The parent would then test its left and right subtree if each contain one of the two nodes. If yes, then the parent must be the LCA and we pass its parent up to the root. If not, we pass the lower node which contains either one of the two nodes (if the left or right subtree contains either p or q), or NULL (if both the left and right subtree does not contain either p or q) up.
*/

struct TreeNode* LCA(struct TreeNode *root, int a, int b)
{
	if(!root)
		return NULL;

	if(root->data == a || root->data == b)
		return root;

	struct TreeNode *left = LCA(root->left, a, b);
	struct TreeNode *right = LCA(root->right, a, b);

	if(left && right)
		return root;
	return left ? left : right;
}

struct TreeNode *LCA_BST(struct TreeNode *root, int a, int b)
{
	if(!root)
		return NULL;

	// the LCA definitely lies in the left subtree
	if(root->data > a && root->data > b)
		LCA_BST(root->left, a, b);

	// the LCA definitely lies in the right subtree
	if(root->data < a && root->data < b)
		LCA_BST(root->right, a, b);

	return root;
}

struct TreeNode* foo(struct ListNode **head, int n)
{
	if(n <= 0) return NULL;
	struct TreeNode *left = foo(head, n/2);
	struct TreeNode *root = new_tree_node((*head)->data);
	root->left = left;
	*head = (*head)->next;
	root->right = foo(head, n-n/2-1);
	return root;
}

int main()
{
	struct ListNode *one = new_list_node(5);	
	struct ListNode *two = new_list_node(10);
	one->next = two;
	struct ListNode *three = new_list_node(13);
	two->next = three;
	struct ListNode *four = new_list_node(17);
	three->next = four;

	print_list(one);
	
	printf("\n");

	//struct TreeNode *tree = foo(&one, 4);
	struct TreeNode *tree = list_to_BST(&one, 0, 3);
	print_inorder(tree);

	printf("\n");
	printf("LCA of 17 and 5: %d\n", (LCA(tree, 17, 5))->data);
	printf("Same but using the BST property: %d\n", 
		(LCA_BST(tree, 17, 5))->data); 
	
	return 0;
}
