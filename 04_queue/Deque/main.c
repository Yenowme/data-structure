#include "deque.h"
#include <stdio.h>

// t_bool	insertHead(List* dq, Node* node);
// Node	*deleteHead(List* dq);
// t_bool	insertRear(List* dq, Node* node);
// Node	*deleteRear(List* dq);

static void	printAll(List* list) {
	lst_print(list->head);
	if (list->head && list->rear) {
		printf("head: %d rear: %d\n", list->head->data, list->rear->data);
		printf("size: %d\n", list->size);
	}
}

int main(int argc, char const *argv[])
{
	List	*list = init();

	printAll(list);
	insertHead(list, nodeNew(1));
	printAll(list);
	insertHead(list, nodeNew(2));
	printAll(list);
	insertHead(list, nodeNew(3));
	printAll(list);
	insertHead(list, nodeNew(4));
	printAll(list);
	insertRear(list, nodeNew(1));
	printAll(list);
	printf("del head %d\n", deleteHead(list)->data);
	printf("del head %d\n", deleteHead(list)->data);
	printf("del rear %d\n", deleteRear(list)->data);
	printf("del rear %d\n", deleteRear(list)->data);
	printf("del rear %d\n", deleteRear(list)->data);
	return 0;
}
