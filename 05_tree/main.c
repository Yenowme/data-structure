#include "bin_tree.h"

int main() {
	printf("🎄🌲🌳make tree🌲🎄🌳\n");
	BinTree *bt = makeBinTree(makeNode('A'));
	BinTreeNode *tmpB = insertLeftChildNodeBT(bt->pRootNode, makeNode('B'));
	BinTreeNode *tmpC = insertRightChildNodeBT(bt->pRootNode, makeNode('C'));

	BinTreeNode *tmpD = insertLeftChildNodeBT(tmpB , makeNode('D'));
	BinTreeNode *tmpE = insertRightChildNodeBT(tmpB , makeNode('E'));

	BinTreeNode *tmpF = insertLeftChildNodeBT(tmpC , makeNode('F'));
	BinTreeNode *tmpG = insertRightChildNodeBT(tmpC , makeNode('G'));

	BinTreeNode *tmpH = insertLeftChildNodeBT(tmpD, makeNode('H'));
	BinTreeNode *tmpI = insertRightChildNodeBT(tmpD, makeNode('I'));

	BinTreeNode *tmpJ = insertLeftChildNodeBT(tmpE, makeNode('J'));

	BinTreeNode *tmpK = insertRightChildNodeBT(tmpF, makeNode('K'));

	BinTreeNode *tmpL = insertLeftChildNodeBT(tmpG, makeNode('L'));
	BinTreeNode *tmpM = insertRightChildNodeBT(tmpG, makeNode('M'));

	preorderTraversal(bt);
	inorderTraversal(bt);
	postorderTraversal(bt);
}
