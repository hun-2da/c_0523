#include<stdio.h>
#include<stdlib.h>
//typedef int element;
typedef struct {
	char name[100];
}element;
typedef struct ListNode { // ��� Ÿ���� ����ü�� �����Ѵ�. element data;
	element data;
	struct ListNode* link;
} ListNode;
ListNode* d_f;	// list�� ������
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
// pre�� ����Ű�� ����� ���� ��带 �����Ѵ�. 
ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed = pre->link;
	d_f = insert_first(d_f, removed->data); //������ ��ũ ����
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
	return NULL; // Ž�� ����
}
int main(void)
{
	ListNode* head = NULL;
	element e;

	head = push(head);
	while (1) {
		
		printf("�޴�\n 1)�߰�\n 2)����\n 3)������ ���� ��� ���\n 4)���α׷� ����\n�Է��� �ֽʽÿ�: ");
		int integer_number = 0; // ���� ����
		char fruit[30]; // �Է�
		scanf_s("%d", &integer_number);

		switch (integer_number) {
		case 1:
			printf("�߰��� ������ �Է��� �ּ���� : ");
			scanf_s("%s", fruit,30);
			
			if (search_list(head, fruit) != NULL) printf("�̹� �����ϴ� �����Դϴ�. \n");
			else {
				strcpy(e.name, fruit);
				head = insert_first(head, e);
				printf("�߰��Ǿ����ϴ�. \n");
			}
			break;
		case 2:
			printf("����Ʈ���� ������ ������ ?! :");
			scanf_s("%s", fruit,30);
			ListNode* p = search_list(head, fruit);

			if (p == NULL) 
				printf("�������� �ʴ� �����Դϴ�. \n");
			else if (p == -1) 
				head = first_delete(head);
			else 
				head = delete(head, p);
			break;
		case 3: print_list(head); break;
		case 4: printf("���α׷��� ����˴ϴ�. "); return 0;
		default:
			printf("�߸��� �Է°��Դϴ�.\n");
		}
	}
}