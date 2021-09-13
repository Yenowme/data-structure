#ifndef ARR_LIST_H
# define ARR_LIST_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

typedef int		Data;
typedef enum	e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct	ArrayQueueNodeType
{
	Data	data;
}	ArrayQueueNode;

typedef struct	ArrayQueueType
{
	int		maxElementCount; //배열 사이즈
	int		currentElementCount; //저장된 원소의 개수
	ArrayQueueNode	*pElement; //1차원 배열
	int		front;
	int		rear;
}	ArrayQueue;

ArrayQueue		*createArrayQueue(int maxElementCount); //배열 생성
void			deleteArrayQueue(ArrayQueue *pList); //배열 삭제
t_bool			isArrayQueueFull(ArrayQueue *pList); //배열 빈공간 있으면 FALSE, 없으면 TRUE
t_bool			addALElement(ArrayQueue *pList, int position, ArrayQueueNode element); //배열 원소 삽입
t_bool			removeALElement(ArrayQueue *pList, int position); //특정 인덱스 원소 삭제
ArrayQueueNode	*getALElement(ArrayQueue *pList, int position); //특정 인덱스 데이터 가져오기
void			displayArrayQueue(ArrayQueue *pList); //배열 원소 출력
void			clearArrayQueue(ArrayQueue *pList); //배열 비우기
int				getArrayQueueLength(ArrayQueue *pList); //배열 길이 가져오기
int				getArrayQueueCapacity(ArrayQueue *pList); //배열 최대크기 가져오기
ArrayQueueNode	*newArrayQueueNode(Data data);


/* arr_queue */
t_bool			enqueue(ArrayQueue*	q, ArrayQueueNode node);
ArrayQueueNode	*dequeue(ArrayQueue *q);
ArrayQueueNode	*peek(ArrayQueue *q);
int				isEmpty(ArrayQueue *q);
int				isFull(ArrayQueue *q);
int				size(ArrayQueue *q);
ArrayQueue		*init(size_t max);



#endif
