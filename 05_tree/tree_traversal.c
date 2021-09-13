# include "bin_tree.h"

static void _inorderTraversal(BinTreeNode *bt)
{
	if (bt->pLeftChild)
		_inorderTraversal(bt->pLeftChild);
	printf("%c ", bt->data);
	if (bt->pRightChild)
		_inorderTraversal(bt->pRightChild);
}

void inorderTraversal(BinTree *bt)
{
	printf("Inorder    : ");
	_inorderTraversal(bt->pRootNode);
	printf("\n");
}

static void _preorderTraversal(BinTreeNode *bt)
{
	printf("%c ", bt->data);
	if (bt->pLeftChild)
		_preorderTraversal(bt->pLeftChild);
	if (bt->pRightChild)
		_preorderTraversal(bt->pRightChild);
}

void preorderTraversal(BinTree *bt)
{
	printf("Preorder   : ");
	_preorderTraversal(bt->pRootNode);
	printf("\n");	
}

static void _postorderTraversal(BinTreeNode *bt)
{
	if (bt->pLeftChild)
		_postorderTraversal(bt->pLeftChild);
	if (bt->pRightChild)
		_postorderTraversal(bt->pRightChild);
	printf("%c ", bt->data);
}

void postorderTraversal(BinTree *bt)
{
	printf("Postorder  : ");
	_postorderTraversal(bt->pRootNode);
	printf("\n");
}
