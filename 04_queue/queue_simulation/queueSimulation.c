#include "queueSimulation.h"
/*
typedef enum SimStatusType {
	arrival,
	start,
	end
}	SimStatus;

typedef struct SimCustomerType {
	SimStatus status; status.arrival = arrival
	int arrivalTime;	// 도착 시간
	int serviceTime;	// 서비스 시간
	int startTime;		// 시작 시간
	int endTime;		// 종료 시간 : 시작 시간 + 서비스 시간
}	SimCustomer;
*/

//고객이 도착했을 때 도착시간, 서비스시간 초기화
SimCustomer *setCustomer(int arrivalTime, int serviceTime){
	SimCustomer *customer;

	customer = (SimCustomer *)malloc(sizeof(SimCustomer));
	if(!customer)
		return NULL;
	customer->status = arrival;
	customer->arrivalTime = arrivalTime;
	customer->serviceTime = serviceTime;
	customer->startTime = 0;
	customer->endTime = 0;

	return customer;
}

/*
	고객이 도착하면 대기열로 enqueue하는 함수
*/
customerArrive(ArrayQueue *arrivalCustomer, ArrayQueue	*watingCustomer, int time)
{
	ArrayQueueNode *tmp;

	if (!(tmp = peek(arrivalCustomer))) {
		printf("No more customers... get off work...");
		return ;
	}
	if (tmp->data->arrivalTime == time && tmp->data->arrivalTime < CLOSE_TIME)
	{
		tmp = dequeue(arrivalCustomer);
		enqueue(watingCustomer, tmp);
		return ;
	}
	printf("no customer have arrived...");
}

int main(void) {
	int			time = 0;
	int			totalWatingtime = 0;

	// 고객 세팅 -> 고객 도착 큐에 enqueue
	SimCustomer	*c1 = setCustomer(0, 3);
	SimCustomer	*c2 = setCustomer(2, 2);
	SimCustomer	*c3 = setCustomer(4, 1);
	SimCustomer	*c4 = setCustomer(6, 1);
	SimCustomer	*c5 = setCustomer(8, 3);

	ArrayQueue	*arrivalCustomer = init(5);
	ArrayQueue	*watingCustomer = init(5);
	ArrayQueue	*completeCustomer = init(5);

	ArrayQueueNode	*serviceCustomer;
	ArrayQueueNode	*tmp;

	//일단 고객을 받아요 -> 고객 도착 큐에 enqueue -> 시간순

	//서비스 시작

	//고객 도착했니? 대기열로 인큐

	//서비스 중이니?
	//	예 : 고객 서비스 타임 감소
	//		서비스 타임 0이니?
	//			예 : 완료 큐로 인큐
	//				서비스 노드 NULL
	//	니오 :
	//		대기열에 고개 있니?
	//			예 : 고객응대

	for(time = 0; time <= CLOSE_TIME; time++)
	{
		// 서비스 종료
		customerArrive(arrivalCustomer, watingCustomer, time);
		if (serviceCustomer->data->serviceTime == 0) {
			serviceCustomer->data->endTime = time;
		}
		if (!serviceCustomer) {
			if (serviceCustomer = dequeue(watingCustomer));
				serviceCustomer->data->status = start;
		} else {
			serviceCustomer->data->serviceTime--;
		}
	}
}

// queue 비었을때 break;

/*

while( (고객 도착 큐 비었음 && 고객 대기 큐 비었음) || 서비스노드가 비었음)
{

	일단 고객을 받아요 -> 고객 도착 큐에 enqueue -> 시간순
	고객이 도착했나?(고객도착 큐, time) -> 고객도착 큐 peek -> 도착시간 == time && 도착시간 < 종료시간 -> dequeue; 아니면 NULL;
	-> dequeue 한 거를 고객 대기 큐에 enqueue;

	----------------- 고객을 받는 과정
	고객 대기큐에서 dequeue 를 해서 하나를 받는다....-> 서비스시간 체크
	서비스시간이 = 0 -> 나가라 -> 메모리 해제

	if (!node) {
		dequeue 해서 노드 채워주고
	}
	---------------대기 고객 처리 과정
*/
