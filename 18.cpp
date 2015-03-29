//给定两棵二叉树A，B。判断树B是不是树A的子结构

#include <isotream>

using namespace std;

struct BinaryTreeNode
{
	int key;
	BinaryTreeNode * left;
	BinaryTreeNode * right;
};

bool isSubStructure(BinaryTreeNode * treeA,BinaryTreeNode * treeB)
{
	if(treeB == NULL)
		return true;
	if(treeA == NULL)
		return false;
	if(treeA->key == treeB->key)
	{
		return isSubStructure(treeA->left,treeB->left) && isSubStructure(treeA->right,treeB->right);
	}
	else
	{
		return isSubStructure(treeA->left,treeB) || isSubStructure(treeA->right,treeB);
	}
}

int main()
{

}
