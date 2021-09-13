#include "arr_list.h"
#include <stdio.h>

//t_bool			enqueue(ArrayQueue*	q, ArrayQueueNode node);
//ArrayQueueNode	*dequeue(ArrayQueue *q);
//ArrayQueueNode	*peek(ArrayQueue *q);
//int				isEmpty(ArrayQueue *q);
//int				size(ArrayQueue *q);
//ArrayQueue		*init(size_t max);

int main(int argc, char const *argv[])
{
	ArrayQueue*	aq = init(3);
	ArrayQueueNode	node;


	node.data = 3;
	if (enqueue(aq, node) == FALSE)
		printf("failed to enqueue %d!\n", node.data);
	node.data = 4;
	if (enqueue(aq, node) == FALSE)
		printf("failed to enqueue %d!\n", node.data);
	node.data = 5;
	if (enqueue(aq, node) == FALSE)
		printf("failed to enqueue %d!\n", node.data);
	node.data = 9;
	if (enqueue(aq, node) == FALSE)
		printf("failed to enqueue %d!\n", node.data);
	printf("dequeue, %d\n", dequeue(aq)->data);
	printf("dequeue, %d\n", dequeue(aq)->data);
	printf("peek, %d\n", peek(aq)->data);
	printf("size, %d\n", size(aq));
	printf("%d\n", dequeue(aq)->data);
	printf("=====front: %d==============rear: %d==================\n", aq->front, aq->rear);
	node.data = 2;
	if (enqueue(aq, node) == FALSE)
		printf("failed to enqueue %d!\n", node.data);
	node.data = 1;
	if (enqueue(aq, node) == FALSE)
		printf("failed to enqueue %d!\n", node.data);
	node.data = 6;
	if (enqueue(aq, node) == FALSE)
		printf("failed to enqueue %d!\n", node.data);
	node.data = 9;
	if (enqueue(aq, node) == FALSE)
		printf("failed to enqueue %d!\n", node.data);
	printf("dequeue, %d\n", dequeue(aq)->data);
	printf("dequeue, %d\n", dequeue(aq)->data);
	printf("peek, %d\n", peek(aq)->data);
	printf("size, %d\n", size(aq));
	printf("=====front: %d==============rear: %d==================\n", aq->front, aq->rear);

	return 0;
}
