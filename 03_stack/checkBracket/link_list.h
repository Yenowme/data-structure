

typedef char element;
// 노드 타입을 구조체로 정의한다.
typedef struct ListNode { 
	element data;
	struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, int value);

ListNode* insert(ListNode* head, ListNode* pre, element value);
ListNode* delete_first(ListNode* head);
ListNode* delete(ListNode* head, ListNode* pre);
void print_list(ListNode* head);