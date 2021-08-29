#ifndef LINKED_LIST
# define LINKED_LIST

#include "./single_linked_list.h""
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 10001

typedef struct _stack
{
	t_node *top;
	int count;
} Stack;

Stack *init(void);
int size(Stack a);
int IsEmpty(Stack a);
int IsFull(Stack a);
void push(Stack *a, t_node *new);
t_node *pop(Stack *a);
t_node *peek(Stack * a);

#endif
