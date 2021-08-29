#include <stdio.h>
#include "single_linked_list_2.h"

t_nodelist	*create_nodelist(void)
{
	t_nodelist	*rt;

	rt = (t_nodelist *)malloc(sizeof(t_nodelist));
	rt->currentElementCount = 0;
	rt->head = NULL;
	return (rt);
}

t_node	*create_node(int degree, int coef)
{
	t_node	*rt;

	rt = (t_node *)malloc(sizeof(t_node));
	rt->degree = degree;
	rt->coef = coef;
	rt->next = NULL;
	return (rt);
}

t_node	*last_node(t_nodelist *lst)
{
	t_node	*rt;

	rt = lst->head;
	if (!rt)
		return (0);
	while (rt->next)
		rt = rt->next;
	return (rt);
}

int	nodelist_is_empty(t_nodelist *list)
{
	if (list->currentElementCount == 0)
		return (1);
	return (0);
}

void	listadd_front(t_nodelist *lst, t_node *new)
{
	new->next = lst->head;
	lst->head = new;
	lst->currentElementCount++;
}

void	listadd_back(t_nodelist *list, t_node *node)
{
	t_node	*temp;

	if (nodelist_is_empty(list))
	{
		list->head = node;
		list->currentElementCount++;
		return ;
	}
	temp = last_node(list);
	temp->next = node;
	list->currentElementCount++;
}

void	lstdelone(t_node *lst)
{
	if (!lst)
		return ;
	free(lst);
}

void	lstclear(t_nodelist *lst)
{
	t_node	*temp;

	while (lst->head->next)
	{
		temp = lst->head->next;
		lstdelone(lst->head);
		lst->head = temp;
	}
	lst->currentElementCount = 0;
}

int	lstsize(t_nodelist *lst)
{
	return (lst->currentElementCount);
}

t_nodelist	*reverse_list(t_nodelist *list)
{
	t_node	*p;
	t_node	*q;
	t_node	*r;

	p = list->head;
	q = NULL;
	while (p != NULL)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	list->head = q;
	return (list);
}

void	lst_print(t_nodelist *lst)
{
	t_node *temp;

	temp = lst->head;
	printf("---\n");
	while (temp)
	{
		printf("degree: %d coef: %d\n", temp->degree, temp->coef);
		temp = temp->next;
	}
	printf("---\n");
}
