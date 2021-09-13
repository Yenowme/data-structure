#include "bin_tree.h"

BinTree* makeBinTree(BinTreeNode *rootNode)
{
	BinTree *newTree;

	newTree = (BinTree *)malloc(sizeof(BinTree));
	if (!newTree)
		return 0;
	newTree->pRootNode = rootNode;
	return newTree;
}

BinTreeNode* makeNode(char data)
{
	BinTreeNode	*newNode;

	newNode = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (!newNode)
		return 0;
	newNode->data = data;
	newNode->visited = FALSE;
	newNode->pLeftChild = NULL;
	newNode->pRightChild = NULL;
	return newNode;
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
	return pBinTree->pRootNode;
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode *element)
{
	if (!pParentNode->pLeftChild)
		pParentNode->pLeftChild = element;
	else {
		printf("This node of left child is full\n");
		return 0;
	}
	return pParentNode->pLeftChild;
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode *element)
{
	if (!pParentNode->pRightChild)
		pParentNode->pRightChild = element;
	else {
		printf("This node of right child is full\n");
		return 0;
	}	
	return pParentNode->pRightChild;
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode->pLeftChild){
		printf("This node of left child is empty");
		return 0;
	}
	else
		return pNode->pLeftChild;;
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode->pRightChild) {
		printf("This node of right child is empty");
		return 0;
	}
	else
		return pNode->pRightChild;
}

void deleteBinTree(BinTree* pBinTree)
{
	if (pBinTree) {
		deleteBinTreeNode(pBinTree->pRootNode);
		free(pBinTree);
		pBinTree = NULL;
	}
}

void deleteBinTreeNode(BinTreeNode* pNode)
{
	if (pNode) {
		if (pNode->pLeftChild) {
			deleteBinTreeNode(pNode->pLeftChild);
		}
		if (pNode->pRightChild) {
			deleteBinTreeNode(pNode->pRightChild);
		}
		free(pNode);
		pNode = NULL;
	}
}
