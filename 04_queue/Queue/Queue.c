#include "Queue.h"

static t_node	*new_node(Value value)
{
	t_node	*new_node = malloc(sizeof(t_node));

	if (new_node == NULL)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

Value		queue_top(t_queue *queue) {
	if (queue == NULL || queue->front == NULL)
		return (ERROR);
	return (queue->front->value);
}

Value		queue_pop(t_queue *queue) {
	if (queue == NULL || queue->front == NULL)
		return (ERROR);

	t_node *tmp = queue->front;
	Value	tmp_value = tmp->value;

	queue->front = queue->front->next;
	queue->queue_size--;
	if (!queue->queue_size)
		queue->rear = NULL;
	free(tmp);
	return (tmp_value);
}

size_t		queue_push(t_queue *queue, Value value) {
	if (queue == NULL)
		return (ERROR);

	t_node	*new_one = new_node(value);

	if (new_one == NULL)
		return (0);
	if (queue->front == NULL)
	{
		queue->front = new_one;
		queue->rear = new_one;
		queue->queue_size = 1;
	}
	else
	{
		queue->rear->next = new_one;
		queue->rear = new_one;
		queue->queue_size++;
	}
	return (queue->queue_size);
}

size_t		queue_size(t_queue *queue) {
	if (queue == NULL)
		return (ERROR);
	return (queue->queue_size);
}

int			queue_empty(t_queue *queue) {
	if (queue == NULL)
		return (ERROR);
	if (queue->queue_size)
		return (FALSE);
	return (TRUE);
}

t_queue*	init_queue() {
	t_queue	*new = malloc(sizeof(t_queue));

	if (new == NULL)
		return (NULL);
	new->front = NULL;
	new->rear = NULL;
	new->queue_size = 0;
	return (new);
}
