#include "stack_link_list.h"
#define TRUE 1;
#define FALSE 0;

int checkBracket(char *str){
	int rt;
	char symbol;
	char temp;
	Stack *stack;

    rt = TRUE;
	stack = init();
	for(int i=0; str[i] && rt; i++) 
	{
		symbol = str[i];
		if (symbol == '(' || symbol == '[' || symbol == '{')
		{
			push(stack, symbol);
			printf("push\n");
			print_list(stack->top);
		}
		else if (symbol == ')' || symbol == ']' || symbol == '}')
		{
			printf("aa\n");
			if (IsEmpty(*stack)){
				rt = FALSE;
            } else
			{
				temp = pop(stack);
				printf("pop");
				print_list(stack->top);
				if (!((symbol - temp) <= 2))
				{
                    printf("result : %c %c\n", temp, symbol);
					rt = FALSE;
				}
			}
		}
	}
	if (!IsEmpty(*stack))
		rt = FALSE;
	return rt;
}

int main(void)
{
	char *str = "((A * B) / C) - {(D + E) && (F - G)}";
    char *str1 = "((A * B) / C - {( D + E) && (F - G))}";

	int rt = checkBracket(str1);


	printf("%d", rt);
}

//gcc -g3 -fsanitize=address 