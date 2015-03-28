//判断一个二叉树是不是平衡二叉树

#include <iostream>

using namespace std;

struct BinaryTreeNode
{
	int key;
	BinaryTreeNode * left;
	BinaryTreeNode * right;
};

bool isBalance(BinaryTreeNode * root,int * height)
{
	if(root == NULL)
	{
		*height = 0;
		return true;
	}
	if(root->left == NULL && root->right == NULL)
	{
		*height = 1;
		return true;
	}
	int leftHeight;
	int rightHeight;
	if(isBalance(root->left,&leftHeight) && isBalance(root->right,&rightHeight))
	{
		*height = leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
		if(leftHeight >= rightHeight && leftHeight - rightHeight <= 1)
			return true;
		else if(rightHeight > leftHeight && rightHeight - leftHeight <= 1)
			return true;
		else
			return false;
	}
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
	node4->left = node5;

	int height = 0;
	if(isBalance(node1,&height))
		cout<<"the tree is balance"<<endl;
	else
		cout<<"the tree is not balance"<<endl;
}
