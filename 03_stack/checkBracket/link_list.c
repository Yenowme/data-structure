#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "link_list.h"

// 앞부분에 노드 삽입
ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //(1)
	p->data = value;
	// (2)
	p->link = head; //(3)
	head = p; //(4)
	return head;
}
/*
ListNode* insert_last(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data =  
}
*/
// 노드 pre 뒤에 새로운 노드 삽입
ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	//(1)
	p->data = value; //(2)
	p->link = pre->link; //(3)
	pre->link = p; //(4)
	return head; //(5)
}
// 앞부분의 노드 제거
ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head; // (1)
	head = removed->link; // (2)
	free(removed); // (3)
	return head; // (4)
}
// pre가 가리키는 노드의 다음 노드를 삭제.
ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link; // (2)
	free(removed); // (3)
	return head; // (4)
}
// 리스트 출력
void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%c->", p->data);
	printf("NULL \n");
}
// 메인/*
/*
int main(void)
{
	ListNode *head = NULL;
    clock_t start, end;

    start = clock();
	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i);
	    print_list(head);
	}
	for (int i = 0; i < 5; i++) {
		head = delete_first(head);
		print_list(head);
	}
    end = clock();
    //print_list(head);
    printf("time: %f", (double)(end - start)/CLOCKS_PER_SEC);
	return 0;
}*/