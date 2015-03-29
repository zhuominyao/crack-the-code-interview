#include <iostream>

using namespace std;

struct BinaryTreeNode
{
	int key;
	BinaryTreeNode * left;
	BinaryTreeNode * right;
};

void ConvertNode(BinaryTreeNode * root,BinaryTreeNode ** last)
{
	if(root->left == NULL && root->right == NULL)//叶子节点
	{
		*last = root;
		return;
	}
	if(root->left != NULL)
		ConvertNode(root->left,last);
	root->left = *last;
	(*last)->right = root;
	if(root->right != NULL)
	{
		ConvertNode(root->right,&root);
	}
}

BinaryTreeNode * Convert(BinaryTreeNode * root)
{
	BinaryTreeNode * last;
	ConvertNode(root,&last);
	while(last->left != NULL)
		last = last->left;
	return last;
}

int main()
{
	BinaryTreeNode * node1 = new BinaryTreeNode();
	BinaryTreeNode * node2 = new BinaryTreeNode();
	BinaryTreeNode * node3 = new BinaryTreeNode();
	node1->key = 2;
	node2->key = 1;
	node3->key = 3;
	node1->left = node2;
	node1->right = node3;
	BinaryTreeNode * head = Convert(node1);
	while(head != NULL)
	{
		cout<<head->key;
		head = head->right;
	}
}
