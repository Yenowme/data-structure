#include "stack_link_list.h"

Stack *init(void)
{
	Stack *a;

	a = (Stack *)malloc(sizeof(Stack));
    a->top = NULL;
	a->count = 0;
	return a;
}

int size(Stack a)
{
    return a.count;
}

int IsEmpty(Stack a)
{
	return a.count == 0;
}

int IsFull(Stack a)
{
    if (a.count >= MAX)
        return 1;
    return 0;
}

void push(Stack *a, t_node *new)
{
	if (IsFull(*a))
	{
		printf("is Full");
		return;
	}
    lstadd_front(&(a->top), new);
    a->count++;
}

t_node *pop(Stack *a)
{
    t_node *ret;

    if (IsEmpty(*a))
	{
        printf("It is empty");
		return ;
	}
    ret = a->top;
    a->top = delete_first(a->top);
    a->count--;
    return ret;
}

t_node	*peek(Stack *a)
{
    t_node *ret;

    if (IsEmpty(*a))
        return 0;
    ret = a->top;

    return ret;
}


int main(){
    int N;
    int Num;
    char str[6];

    Stack *stack;

    scanf("%d", &N);

    stack = init();

    for (int i = 0; i < N; i++)
    {
        scanf("%s", str);
        if (!strcmp(str, "push"))
        {
            scanf("%d", &Num);

            push(stack, Num);
        }
        else if (!strcmp(str, "pop"))
            printf("%d\n", pop(stack));
        else if (!strcmp(str, "empty"))
            printf("%d\n", IsEmpty(*stack));
        else if (!strcmp(str, "size"))
            printf("%d\n", size(*stack));
        else if (!strcmp(str, "top"))
            printf("%d\n", peek(stack));
    }
}
