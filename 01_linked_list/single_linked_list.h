#ifndef SINGLE_LINKED_LIST_H
# define SINGLE_LINKED_LIST_H

# include <stdlib.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}				t_node;

t_node	*lstnew(int data);
t_node	*lstlast(t_node *lst);
void	lstadd_front(t_node **lst, t_node *n );
void	lstadd_back(t_node **list, t_node *n);
void	lstdelone(t_node *lst);
void	lstclear(t_node **lst);
int		lstsize(t_node *lst);
void	lst_print(t_node *lst);
t_node	*reverse_list(t_node *head);

#endif
