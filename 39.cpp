//求二叉树的深度


#include <iostream>

using namespace std;

struct BinaryTreeNode
{
	BinaryTreeNode * left;
	BinaryTreeNode * right;
	int key;
};

int max(int a,int b)
{
	return a > b ? a : b;
}
int getBinaryTreeDepth(BinaryTreeNode * root)
{
	if(root == NULL)
		return 0;
	if(root->left == NULL && root->right == NULL)
		return 1;
	int leftDepth = 0;
	int rightDepth = 0;
	if(root->left != NULL)
		leftDepth = getBinaryTreeDepth(root->left);
	if(root->right != NULL)
		rightDepth = getBinaryTreeDepth(root->right);
	return max(leftDepth,rightDepth) + 1;
}

int main()
{
	BinaryTreeNode * node1 = new BinaryTreeNode();
	BinaryTreeNode * node2 = new BinaryTreeNode();
	BinaryTreeNode * node3 = new BinaryTreeNode();
	BinaryTreeNode * node4 = new BinaryTreeNode();
	BinaryTreeNode * node5 = new BinaryTreeNode();

	node1->key = 1;
	node2->key = 2;
	node3->key = 3;
	node4->key = 4;
	node5->key = 5;

	node1->left = node2;
	node1->right = node3;
	node3->left = node4;
	node3->right = node5;

	cout<<getBinaryTreeDepth(node1);
}
