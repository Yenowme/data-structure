# ifndef HEAP_C
#define HEAP_C

#include <stdlib.h>

typedef struct HeapNodeType
{
	int key;
	char value;
} HeapNode;

typedef struct HeapType
{
	HeapNode *pElement; //heap배열 
	int maxElementCount;
	int currentElementCount;
} Heap;

Heap *initHeap(int max);
int insertMaxHeap(Heap *pHeap, HeapNode element);
int insertMinHeap(Heap *pHeap, HeapNode element);
HeapNode deleteMaxHeap(Heap *hp);


#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

# endif
