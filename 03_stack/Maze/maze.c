#include "stack_link_list.h"

#define MAZE_SIZE 8
#include <unistd.h>

/*
** 0 = 길
** 1 = 벽
** 2 = 방문
** 3 = 출구
*/
int maze[MAZE_SIZE + 1][MAZE_SIZE + 1] = {
	{0, 0, 1, 0, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, },
	{1, 0, 1, 0, 1, 0, 1, 1},
	{1, 1, 1, 0, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 0, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0},
	{1, 1, 1, 3, 1, 1, 1, 0}};

void goMaze(Stack *way, int x, int y)
{
	t_node *temp;

	if(x < 0 || y < 0 || x >= MAZE_SIZE || y >= MAZE_SIZE) return ;
	if (maze[x][y] != 1 && maze[x][y] != 2)
	{
		temp = lstnew(x, y);
		push(way, temp);
	}
}

void printMaze(int x, int y)
{
	sleep(2);
	system("clear");
	for (int i = 0; i < MAZE_SIZE; i++)
	{
		for (int j = 0; j < MAZE_SIZE; j++)
		{
			if (i == x && j == y)
				printf("😀");
			else if (maze[i][j] == 0)
				printf("◽️");
			else if (maze[i][j] == 1)
				printf("◾️");
			else if (maze[i][j] == 2)
				printf("✔️ ");
			else if (maze[i][j] == 3)
			{
				printf("🚩");
			}
		}
		printf("\n");
	}
	fflush(stdout);
}

int main()
{

	Stack *s;
	t_node *me;
	int x, y;

	s = init();
	me = lstnew(1,3);
	x = me->x;
	y = me->y;

	printf("미로찾기 시작\n");

	printMaze(x,y);
	while (maze[x][y] != 3)
	{
		maze[x][y] = 2;
		goMaze(s,x,y-1);
		goMaze(s,x-1,y);
		goMaze(s,x,y+1);
		goMaze(s,x+1,y);

		if(IsEmpty(*s))
		{
			printf("이동경로 없음\n");
			return 0;
		}
		else
		{
			lstdelone(me);
			me = pop(s); //좌표변경
			printf("x:%d y:%d\n", me->x, me->y);
			printMaze(x,y);
			lst_print(s->top);
		}
		x = me->x;
		y = me->y;
	}
	printMaze(x,y);
	printf("도착");
	lst_print(s->top);
}
