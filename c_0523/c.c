#include<stdio.h>
#include<stdlib.h>
//typedef int element;
typedef struct {
	char name[30];
}element;
typedef struct ListNode { // 노드 타입을 구조체로 정의한다. element data;
	element data;
	struct ListNode* link;
} ListNode;
ListNode* d_f;	// list의 사이즈
ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p =
		(ListNode*)malloc(sizeof(ListNode));//(1)
	p->data = value;
	// (2)
	p->link = head; //(3)
	head = p; //(4)
	return head;
}
// pre가 가리키는 노드의 다음 노드를 삭제한다. 
ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed = pre->link;
	d_f = insert_first(d_f, removed->data); //삭제용 링크 삽입
	pre->link = removed->link; // (2)
	free(removed); // (3)
	return head; // (4)
}
ListNode* first_delete(ListNode* head)
{
	d_f = insert_first(d_f, head->data);
	head = head->link;
	return head;
}
void print_list(ListNode* head)
{
	printf("List : ");
	for (ListNode* p = d_f; p != NULL; p = p->link)
		printf("%s  ", p->data.name);

	printf("\n");
}
ListNode* push(ListNode* head) {
	element e;
	strcpy(e.name, "Apple");
	head = insert_first(head, e);
	strcpy(e.name, "Mango");
	head = insert_first(head, e);
	strcpy(e.name, "Orange");
	head = insert_first(head, e);
	strcpy(e.name, "Grape");
	head = insert_first(head, e);
	strcpy(e.name, "Cherry");
	head = insert_first(head, e);
	strcpy(e.name, "Plum");
	head = insert_first(head, e);
	strcpy(e.name, "Guava");
	head = insert_first(head, e);
	strcpy(e.name, "Raspbarry");
	head = insert_first(head, e);
	strcpy(e.name, "Banana");
	head = insert_first(head, e);
	strcpy(e.name, "Peach");
	head = insert_first(head, e);
	return head;
}
ListNode* search_list(ListNode* head, char* x)
{
	ListNode* p = head;
	ListNode* choice_Node = NULL;
	while (p != NULL) {
		int compare = strcmp(p->data.name,x);
		if (compare == 0) {
			if (choice_Node == NULL) choice_Node = -1;
			return choice_Node;
		}
		choice_Node = p;
		p = p->link;
	}
	return NULL; // 탐색 실패
}
int main(void)
{
	ListNode* head = NULL;
	element e;

	head = push(head);
	while (1) {
		
		printf("메뉴\n 1)추가\n 2)삭제\n 3)삭제된 과일 모두 출력\n 4)프로그램 종료\n입력해 주십시오: ");
		int integer_number = 0; // 삽입 숫자
		char fruit[30]; // 입력
		scanf_s("%d", &integer_number);

		switch (integer_number) {
		case 1:
			printf("추가할 과일을 입력해 주세요오 : ");
			scanf_s("%s", fruit,30);
			
			if (search_list(head, fruit) != NULL) printf("이미 존재하는 과일입니다. \n");
			else {
				strcpy(e.name, fruit);
				head = insert_first(head, e);
				printf("추가되었습니다. \n");
			}
			break;
		case 2:
			printf("리스트에서 삭제할 과일은 ?! :");
			scanf_s("%s", fruit,30);
			ListNode* p = search_list(head, fruit);

			if (p == NULL) 
				printf("존재하지 않는 과일입니다. \n");
			else if (p == -1) 
				head = first_delete(head);
			else 
				head = delete(head, p);
			break;
		case 3: print_list(head); break;
		case 4: printf("프로그램이 종료됩니다. "); return 0;
		default:
			printf("잘못된 입력값입니다.\n");
		}
	}
}
