#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}				t_list;

t_list	*lstnew(int data)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->data = data;
	new->next = NULL;
	return (new);
}

t_list	*lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

void	lstadd_back(t_list **list, t_list *new)
{
	t_list	*temp;

	if (!(*list))
	{
		*list = new;
		return ;
	}
	temp = lstlast(*list);
	temp->next = new;
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

int	lstsize(t_list *lst)
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


int main(void)
{
	t_list	*lst;
	t_list	*new;

	lst = lstnew(1);
	lst_print(lst);
	lstadd_back(&lst, lstnew(2));
	lstadd_back(&lst, lstnew(4));
	lstadd_front(&lst, lstnew(7));
	lstadd_back(&lst, lstnew(-7));
	lst_print(lst);
	lst_print(lst);
	lstclear(&lst);
	lst_print(lst);
}
