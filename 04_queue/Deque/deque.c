#include "deque.h"

t_bool	insertHead(List* dq, Node* node) {
	if (node == NULL)
		return FALSE;
	lstadd_front(dq, node);
	return TRUE;
}

Node	*deleteHead(List* dq) {
	if (listIsEmpty(dq))
		return NULL;
	Node	*ret = dq->head;
	if (dq->size == 1) {
		dq->head = NULL;
		dq->rear = NULL;
		dq->size = 0;
		return ret;
	}
	dq->head = dq->head->next;
	ret->next = NULL;
	ret->prev = NULL;
	dq->size--;
	return ret;
}

t_bool	insertRear(List* dq, Node* node) {
	if (listIsEmpty(dq)){
		dq->head = node;
		dq->rear = node;
		dq->size = 1;
		return TRUE;
	}
	dq->rear->next = node;
	node->prev = dq->rear;
	dq->rear = node;
	dq->size++;
	return TRUE;
}

Node	*deleteRear(List* dq) {
	if (listIsEmpty(dq))
		return NULL;
	Node	*ret = dq->rear;
	if (dq->size == 1) {
		dq->head = NULL;
		dq->rear = NULL;
		dq->size = 0;
		return ret;
	}
	dq->rear = dq->rear->prev;
	ret->next = NULL;
	ret->prev = NULL;
	dq->size++;
	return ret;
}

