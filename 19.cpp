//写一个函数，输入一个二叉树，该函数输出它的镜像

#inlcude <iostream>

struct BinaryTreeNode
{
	int key;
	BinaryTreeNode * left;
	BinaryTreeNode * right;
};

using namespace std;

BinaryTreeNode binaryTreeNodeMirror(BinaryTreeNode * tree)
{
	if(tree == NULL)
		return;
	BinaryTreeNode * mirrorTree = new BinaryTreeNode();
	mirrorTree->key = tree->key;
	if(tree->left != NULL)
		mirrorTree->right = binaryTreeNodeMirror(tree->left);
	if(tree->right != NULL)
		mirrorTree->left = binaryTreeNodeMirror(tree->right);
}

int main()
{

}
