#include "arr_list.h"

ArrayQueue	*createArrayQueue(int maxElementCount) //배열 생성
{
	ArrayQueue	*new;

	new = (ArrayQueue *)malloc(sizeof(ArrayQueue));
	if (!new)
		return (0);
	new->pElement = (ArrayQueueNode *)malloc(sizeof(ArrayQueueNode) * maxElementCount);
	if (!new->pElement)
	{
		free(new);
		return (0);
	}
	new->maxElementCount = maxElementCount;
	new->currentElementCount = 0;
	new->front = 0;
	new->rear = 0;
	return (new);
}

ArrayQueueNode	*newArrayQueueNode(Data data){
	ArrayQueueNode *rt;

	rt = malloc(sizeof(ArrayQueueNode));
	if (rt == NULL)
		return NULL;
	rt->data = data;
	return rt;
}

void	deleteArrayQueue(ArrayQueue *pList) //배열 삭제
{
	free(pList->pElement);
	free(pList);
	pList->currentElementCount = 0;
	pList->maxElementCount = 0;
	pList->front = 0;
	pList->rear = 0;
}

t_bool	isArrayQueueFull(ArrayQueue *pList) //배열 빈공간 있으면 FALSE, 없으면 TRUE
{
	if (pList->maxElementCount == pList->currentElementCount)
		return (TRUE);
	return (FALSE);
}

t_bool	addALElement(ArrayQueue *pList, int position, ArrayQueueNode element) //배열 원소 삽입
{
	ArrayQueueNode	*tmp;

	if (!pList)
		return (FALSE);
	if (position > pList->currentElementCount) //추가
	position = pList->currentElementCount;
	if (position >= pList->maxElementCount)
	{
		tmp = realloc(pList->pElement, sizeof(ArrayQueueNode) * (position + 1));
		if (!tmp)
			return (FALSE);
		pList->pElement = tmp;
		pList->maxElementCount = position + 1;
	}
	if (isArrayQueueFull(pList)) //추가
	{
		pList->maxElementCount++;
		tmp = realloc(pList->pElement, sizeof(ArrayQueueNode) * (pList->maxElementCount));
		pList->pElement = tmp;
	}
	for (int i = pList->currentElementCount - 1; i >= position ; i--) //추가
		pList->pElement[i + 1] = pList->pElement[i];
	pList->pElement[position] = element;
	pList->currentElementCount++;
	return (TRUE);
}

t_bool	removeALElement(ArrayQueue *pList, int position) //특정 인덱스 원소 삭제
{
	ArrayQueueNode	data;

	data.data = 0;
	if (!pList)
		return (FALSE);
	for (int i = position; i < pList->currentElementCount; i++)
	{
		if (i + 1 == pList->maxElementCount)
			pList->pElement[i] = data;
		else
			pList->pElement[i] = pList->pElement[i + 1];
	}
	pList->pElement[pList->currentElementCount - 1] = data;
	pList->currentElementCount--;
	return (TRUE);
}

ArrayQueueNode	*getALElement(ArrayQueue *pList, int position) //특정 인덱스 데이터 가져오기
{
	return (&(pList->pElement[position]));
}

void	displayArrayQueue(ArrayQueue *pList) //배열 원소 출력
{
	for (int i = 0; i < pList->currentElementCount; i++)
		printf("pList[%d] = %d\n", i, pList->pElement[i].data);
}

void	clearArrayQueue(ArrayQueue *pList) //배열 비우기
{
	ArrayQueueNode	data;

	data.data = 0;
	for (int i = 0; i < pList->currentElementCount; i++)
		pList->pElement[i] = data;
	pList->currentElementCount = 0;
}

int	getArrayQueueLength(ArrayQueue *pList) //배열 길이 가져오기
{
	return (pList->currentElementCount);
}

int	getArrayQueueCapacity(ArrayQueue *pList) //배열 최대크기 가져오기
{
	return (pList->maxElementCount);
}
