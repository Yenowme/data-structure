#include "single_linked_list_2.h"

t_nodelist	*polynomial_addition(t_nodelist *a, t_nodelist *b)
{
	t_node		*node_a;
	t_node		*node_b;
	t_node		*tmp;
	t_nodelist	*rt;

	node_a = a->head;
	node_b = b->head;
	rt = create_nodelist();
	while (node_a || node_b)
	{
		if (node_b && node_a && (node_a->degree == node_b->degree))
		{
			tmp = create_node(node_a->degree, node_a->coef + node_b->coef);
			listadd_back(rt, tmp);
			node_b = node_b->next;
			node_a = node_a->next;
		}
		else if (node_a && ((!node_b && node_a) || (node_a->degree > node_b->degree)))
		{
			tmp = create_node(node_a->degree, node_a->coef);
			listadd_back(rt, tmp);
			node_a = node_a->next;
		}
		else if (node_b &&(!node_a && node_b ) || (node_a->degree < node_b->degree))
		{
			tmp = create_node(node_b->degree, node_b->coef);
			listadd_back(rt, tmp);
			node_b = node_b->next;
		}
	}
	return (rt);
}

int	main(void)
{
	t_nodelist	*a;
	t_nodelist	*b;
	t_nodelist	*c;

	a = create_nodelist();
	b = create_nodelist();
	listadd_back(a, create_node(6, 6));
	listadd_back(a, create_node(5, 4));
	listadd_back(a, create_node(2, 2));
	listadd_back(b, create_node(5, 1));
	listadd_back(b, create_node(4, 2));
	listadd_back(b, create_node(2, 3));
	listadd_back(b, create_node(0, 4));
	lst_print(a);
	lst_print(b);
	c = polynomial_addition(a, b);
	lst_print(c);
	lstclear(a);
	lstclear(b);
	lstclear(c);
}
