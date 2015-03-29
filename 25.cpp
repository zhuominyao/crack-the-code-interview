//打印出一个二叉树中节点值的和为输入整数的所有路径

#include <iostream>
#include <vector>

using namespace std;

struct BinaryTreeNode
{
	int key;
	BinaryTreeNode * left;
	BinaryTreeNode * right;
};

void printPath(BinaryTreeNode * tree,int sum,vector<int> node)
{
	if(tree == NULL)
		return;
	if(tree->key == sum)
	{
		node.push_back(tree->key);
		for(int i = 0;i < node.size();i++)
			cout<<node[i]<<endl;
		cout<<endl;
		return;
	}
	else if(tree->key < sum)
	{
		node.push_back(tree->key);
		if(tree->left != NULL)
			printPath(tree->left,sum - tree->key,node);
		if(tree->right != NULL)
			printPath(tree->right,sum - tree->key,node);
	}
}

int main()
{
	BinaryTreeNode * node1 = new BinaryTreeNode();
	BinaryTreeNode * node2 = new BinaryTreeNode();
	BinaryTreeNode * node3 = new BinaryTreeNode();
	BinaryTreeNode * node4 = new BinaryTreeNode();
	BinaryTreeNode * node5 = new BinaryTreeNode();
	node1->key = 10;
	node2->key = 5;
	node3->key = 12;
	node4->key = 4;
	node5->key = 7;
	node1->left = node2;
	node1->right = node3;
	node2->left = node4;
	node2->right = node5;
	vector<int> node;
	printPath(node1,22,node);
}
