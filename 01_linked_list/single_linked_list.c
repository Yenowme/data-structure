#include <stdio.h>
#include "single_linked_list.h"

t_node	*lstnew(int data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->data = data;
	new->next = NULL;
	return (new);
}

t_node	*lstlast(t_node *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	lstadd_front(t_node **lst, t_node *new)
{
	new->next = *lst;
	*lst = new;
}

void	lstadd_back(t_node **list, t_node *new)
{
	t_node	*temp;

	if (!(*list))
	{
		*list = new;
		return ;
	}
	temp = lstlast(*list);
	temp->next = new;
}

void	lstdelone(t_node *lst)
{
	if (!lst)
		return ;
	free(lst);
}

void	lstclear(t_node **lst)
{
	while (*lst)
	{
		lstdelone(*lst);
		*lst = (*lst)->next;
	}
}

int	lstsize(t_node *lst)
{
	int	rt;

	if (!lst)
		return (0);
	rt = 1;
	while (lst->next)
	{
		rt++;
		lst = lst->next;
	}
	return (rt);
}

t_node	*reverse_list(t_node *head)
{
	t_node	*p;
	t_node	*q;
	t_node	*r;

	p = head;
	q = NULL;
	while (p != NULL)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	return (q);
}

void	lst_print(t_node *lst)
{
	printf("[");
	while (lst)
	{
		printf(" %d", lst->data);
		lst = lst->next;
	}
	printf(" ]\n");
}

int main(void)
{
	t_node	*lst;
	t_node	*new;

	lst = lstnew(1);
	lst_print(lst);
	lstadd_back(&lst, lstnew(2));
	lstadd_back(&lst, lstnew(4));
	lstadd_front(&lst, lstnew(7));
	lstadd_back(&lst, lstnew(-7));
	lst_print(lst);
	lst = reverse_list(lst);
	lst_print(lst);
	lstclear(&lst);
	lst_print(lst);
}
