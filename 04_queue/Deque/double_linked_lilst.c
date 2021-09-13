#include "double_linked_list.h"

List	*init(void)
{
	List *newList;

	newList = (List *)malloc(sizeof(List));
	newList->head = NULL;
	newList->rear = NULL;
	newList->size = 0;
	return newList;
}

Node	*nodeNew(Data data)
{
	Node	*new;

	new = (Node *)malloc(sizeof(Node));
	new->data = data;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

Node	*lstlast(List *lst)
{
	Node *last;

	if (listIsEmpty(lst))
		return (0);
	last = lst->head;
	while (last->next)
	{
		last = last->next;
	}
	return (last);
}

t_bool	listIsEmpty(List *lst)
{
	return lst->size <= 0;
}

void	lstadd_front(List *list, Node *newNode)
{
	if (listIsEmpty(list))
	{
		list->head = newNode;
		list->rear = newNode;
		list->size = 1;
		return ;
	}
	newNode->next = list->head;
	list->head->prev = newNode;
	list->head = newNode;
	list->size++;
}

void	lstadd_back(List *list, Node *new)
{
	Node *temp;

	if (listIsEmpty(list))
	{
		list->head = new;
		list->rear = new;
		list->size = 1;
		return ;
	}
	temp = lstlast(list);
	new->prev = temp;
	temp->next = new;
	list->size++;
}

void	lstdelone(Node *node)
{
	if (!node)
		return ;
	free(node);
}

void	lstclear(List *lst)
{
	Node *temp;

	while (lst->head->next)
	{
		temp = lst->head->next;
		lstdelone(lst->head);
		lst->head = temp;
	}
	lst->size = 0;
}

void	lst_print(Node *lst)
{
	if (!lst)
	{
		printf("(null)\n");
		return ;
	}
	printf("[");
	while (lst)
	{
		printf(" %d", lst->data);
		lst = lst->next;
	}
	printf(" ]\n");
}

//int	main(void)
//{
//	Node	*lst;

//	lst = lstnew(1);
//	lstadd_back(lst, lstnew(2));
//	lstadd_back(lst, lstnew(3));
//	lstadd_back(lst, lstnew(4));
//	lst_print(lst);
//}
