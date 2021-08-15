#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
	struct s_list	*prev;
}			t_list;

t_list	*lstnew(int data)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->data = data;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_list	*lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

t_list	*lstfirst(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->prev)
	{
		lst = lst->prev;
	}
	return (lst);
}

void	lstadd_front(t_list *list, t_list *new)
{
	if (!list)
	{
		list = new;
		return ;
	}
	list = lstfirst(list);
	new->next = list;
	list->prev = new;
}

void	lstadd_back(t_list *list, t_list *new)
{
	if (!list)
	{
		list = new;
		return ;
	}
	list = lstlast(list);
	new->prev = list;
	list->next = new;
}

void	lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	free(lst);
}

void	lstclear(t_list **lst)
{
	while (*lst)
	{
		lstdelone(*lst);
		*lst = (*lst)->next;
	}
}

void	lst_print(t_list *lst)
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

int	main(void)
{
	t_list	*lst;

	lst = lstnew(1);
	lstadd_back(lst, lstnew(2));
	lstadd_back(lst, lstnew(3));
	lstadd_back(lst, lstnew(4));
	lst_print(lst);
}
