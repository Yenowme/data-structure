#include "arr_list.h"

t_bool	enqueue(ArrayQueue*	q, ArrayQueueNode node){
	if (isFull(q))
		return FALSE;
	q->pElement[q->rear] = node;
	q->rear = (q->rear + 1) % q->maxElementCount;
	q->currentElementCount++;
	return TRUE;
}

ArrayQueueNode	*dequeue(ArrayQueue *q){
	ArrayQueueNode	*rt;

	if (isEmpty(q))
		return NULL;
	rt = newArrayQueueNode(q->pElement[q->front].data);
	q->front = (q->front + 1) % q->maxElementCount;
	q->currentElementCount--;
	return rt;
}

ArrayQueueNode	*peek(ArrayQueue *q){
	ArrayQueueNode	*rt;

	if (isEmpty(q))
		return NULL;
	rt = newArrayQueueNode(q->pElement[q->front].data);
	return rt;
}

int		isFull(ArrayQueue *q){
	return q->maxElementCount == q->currentElementCount;
}

int		isEmpty(ArrayQueue *q){
	return q->currentElementCount <= 0;
}

int		size(ArrayQueue *q){
	return q->currentElementCount;
}

ArrayQueue	*init(size_t max){
	ArrayQueue	*newQueue;

	newQueue = createArrayQueue(max);
	return	newQueue;
}

