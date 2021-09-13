#include "binsearchtree.h"

BinSearchTree *createBinSearchTree()
{
    BinSearchTree *rt;

    rt = (BinSearchTree *)malloc(sizeof(BinSearchTree));
    rt->pRootNode = NULL;
    return rt;
}

BinSearchTreeNode *makeElementBST(int key, char value)
{
    BinSearchTreeNode *rt;

    rt = (BinSearchTreeNode *)malloc(sizeof(BinSearchTreeNode));
    rt->key = key;
    rt->value = value;
    rt->pLeftChild = NULL;
    rt->pRightChild = NULL;
    return rt;
}

int insertElementBST(BinSearchTree *pBinSearchTree, BinSearchTreeNode *element)
{
    BinSearchTreeNode *tmp;

    if (!pBinSearchTree)
        return FALSE;
    if (searchRecursiveBST(pBinSearchTree, element->key))
        return FALSE;

    tmp = pBinSearchTree->pRootNode;

    while (tmp != NULL)
    {
        if (element->key < tmp->key)
        {
            tmp = tmp->pLeftChild; //작으면 왼쪽 노드로 이동
        }
        else
        {
            tmp = tmp->pRightChild; //크면 오른쪽 노드로 이동
        }
    }
    tmp = element;
    return TRUE;
}

static BinSearchTreeNode *minValueNode(BinSearchTreeNode *node)
{
    BinSearchTreeNode* current = node;
	
    while (current && current->pLeftChild != NULL)
        current = current->pLeftChild;
    return current;
}

BinSearchTreeNode* findrootNodeBST(BinSearchTreeNode *root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->key)
        root->pLeftChild = findrootNodeBST(root->pLeftChild, key); //call 
    else if (key > root->key)
        root->pRightChild = findrootNodeBST(root->pRightChild, key);
	else {
        if (root->pLeftChild == NULL) {
            BinSearchTreeNode* temp = root->pRightChild;
            free(root);
            return temp;
        }
        else if (root->pRightChild == NULL) {
            BinSearchTreeNode* temp = root->pLeftChild;
            free(root);
            return temp;
        }
		BinSearchTreeNode* temp = minValueNode(root->pRightChild);
		root->key = temp->key;
        root->pRightChild = findrootNodeBST(root->pRightChild, temp->key);//call
    }
	return root;
}

int deleteElementBST(BinSearchTree *root, int key)
{	
	if (!searchRecursiveBST(root, key))
		return FALSE;
	root->pRootNode = findrootNodeBST(root->pRootNode, key);
	return TRUE;
}


BinSearchTreeNode *searchRecursiveBST(BinSearchTree *pBinSearchTree, int key)
{
    BinSearchTreeNode *result;
	result = searchInternalRecursiveBST(pBinSearchTree->pRootNode, key);
	return result;
}

BinSearchTreeNode *searchInternalRecursiveBST(BinSearchTreeNode *pTreeNode, int key)
{
    if (pTreeNode == NULL)
    {
        printf("Key Not found\n");
        return;
    }
    if (key == pTreeNode->key)
    {
        return pTreeNode;
    }
    else if (key < pTreeNode->key)
    {
        return searchInternalRecursiveBST(pTreeNode->pLeftChild, key); //작으면 왼쪽 노드로 이동
    }
    else
    {
        return searchInternalRecursiveBST(pTreeNode->pRightChild, key); //크면 오른쪽 노드로 이동
    }
}

BinSearchTreeNode *searchBST(BinSearchTree *pBinSearchTree, int key)
{
    BinSearchTreeNode *result;

    result = pBinSearchTree->pRootNode;

    while (result != NULL)
    {
        if (key == result->key)
        {
            break;
        }
        else if (key < result->key)
        {
            result = result->pLeftChild; //작으면 왼쪽 노드로 이동
        }
        else
        {
            result = result->pRightChild; //크면 오른쪽 노드로 이동
        }
    }
    if (result == NULL)
        printf("Key Not found\n");
    return result;
}

void deleteBinSearchTree(BinSearchTree *pBinSearchTree)
{
	if (!pBinSearchTree->pRootNode)
		return ;
	deleteBinSearchTreeInternal(pBinSearchTree->pRootNode);
	free(pBinSearchTree);
}

void deleteBinSearchTreeInternal(BinSearchTreeNode *pDelNode)
{
	if (pDelNode == NULL)
		return;
	deleteBinSearchTreeInternal(pDelNode->pRightChild);
	deleteBinSearchTreeInternal(pDelNode->pLeftChild);
	free(pDelNode);
}
