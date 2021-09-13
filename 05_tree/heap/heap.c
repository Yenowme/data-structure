
#include "heap.h"

Heap *initHeap(int max)
{
	Heap *rt;

	rt = (Heap *)malloc(sizeof(Heap));
	rt->pElement = (HeapNode *)malloc(sizeof(HeapNode) * max);
	rt->maxElementCount = max;
	rt->currentElementCount = 0;
}

int insertMaxHeap(Heap *pHeap, HeapNode element)
{
	if (pHeap->currentElementCount == pHeap->maxElementCount)
	{
		printf("heap overflow");
		return FALSE;
	}
	pHeap->currentElementCount = pHeap->currentElementCount + 1;
	int i = pHeap->currentElementCount;

	while (i != 1 && element.key > pHeap->pElement[i / 2].key)
	{
		pHeap->pElement[i] = pHeap->pElement[i / 2];
		i = i / 2;
	}
	pHeap->pElement[i] = element;
	return TRUE;
}

int insertMinHeap(Heap *pHeap, HeapNode element)
{
	if (pHeap->currentElementCount == pHeap->maxElementCount)
	{
		printf("heap overflow");
		return FALSE;
	}
	pHeap->currentElementCount = pHeap->currentElementCount + 1;
	int i = pHeap->currentElementCount;

	while (i != 1 && element.key < pHeap->pElement[i / 2].key)
	{
		pHeap->pElement[i] = pHeap->pElement[i / 2];
		i = i / 2;
	}
	pHeap->pElement[i] = element;
	return TRUE;
}

HeapNode deleteMaxHeap(Heap *pHeap)
{
	HeapNode rt;
	HeapNode temp;
	int i;
	int parent = 1;
	int child = 2;

	if (!pHeap)
	{
		printf("heap not found\n");
		return;
	}
	rt = pHeap->pElement[1];
	i = pHeap->currentElementCount;
	temp = pHeap->pElement[i];
	pHeap->currentElementCount = pHeap->currentElementCount - 1;
	while (child <= pHeap->currentElementCount)
	{
		if ((child < pHeap->currentElementCount) && pHeap->pElement[child].key < pHeap->pElement[child + 1].key)
			child = child + 1;
		if (temp.key >= pHeap->pElement[child].key)
			break;
		pHeap->pElement[parent] = pHeap->pElement[child];
		parent = child;
		child = child * 2;
	}
	pHeap->pElement[parent] = temp;
	return rt;
}
