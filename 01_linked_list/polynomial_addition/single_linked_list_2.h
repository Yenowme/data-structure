#ifndef SINGLE_LINKED_LIST_2_H
# define SINGLE_LINKED_LIST_2_H

# include <stdlib.h>

typedef struct s_node
{
	int				coef;
	int				degree;
	struct s_node	*next;
}				t_node;

typedef struct s_nodelist
{
	int		currentElementCount;
	t_node	*head;
}			t_nodelist;

t_nodelist	*create_nodelist(void);
t_node		*create_node(int degree, int coef);
t_node		*last_node(t_nodelist *lst);
int			nodelist_is_empty(t_nodelist *list);
void		listadd_front(t_nodelist *lst, t_node *new);
void		listadd_back(t_nodelist *list, t_node *node);
void		lstdelone(t_node *lst);
void		lstclear(t_nodelist *lst);
int			lstsize(t_nodelist *lst);
t_nodelist	*reverse_list(t_nodelist *list);
void		lst_print(t_nodelist *lst);

#endif
