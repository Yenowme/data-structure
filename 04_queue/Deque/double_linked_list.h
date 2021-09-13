#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>

typedef int Data;

typedef	enum e_bool {
	FALSE,
	TRUE
}t_bool;

typedef struct _node
{
	Data			data;
	struct _node	*next;
	struct _node	*prev;
} Node;

typedef struct _list
{
	Node	*head;
	Node	*rear;
	int		size;
} List;

Node	*nodeNew(Data data);
Node	*lstlast(List *lst);
t_bool	listIsEmpty(List *lst);
void	lstadd_front(List *list, Node *newNode);
void	lstadd_back(List *list, Node *new);
void	lstdelone(Node *lst);
void	lstclear(List *lst);
List	*init(void);
void	lst_print(Node *lst);

#endif
