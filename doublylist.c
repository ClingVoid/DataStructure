#include<stdio.h>
#include<stdlib.h>
#define ELEMTYPE int
typedef struct node {
	ELEMTYPE data;
	struct node* Next;
	struct node* Previous;
}Node;
void __init__(Node** head) {
	*head = malloc(sizeof(Node));
	if (*head == NULL) {
		printf("init fail");
		return;
	}
	(*head)->Next = *head;
	(*head)->Previous = *head;
}
int insert_head(Node* head, ELEMTYPE new_data) {
	Node* new_node = malloc(sizeof(Node));
	if (new_node == NULL) {
		printf("fail");
		return 0;
	}
	Node* p = head;
	new_node->data = new_data;
	new_node->Next = p->Next;
	new_node->Previous = p;
	p->Next->Previous = new_node;
	p->Next = new_node;
	return 1;
}
int insert_tail(Node* head, ELEMTYPE new_data) {
	Node* p = head->Previous;
	Node* new_node = malloc(sizeof(Node));
	if (new_node == NULL) {
		printf("fail");
		return 0;
	}
	new_node->data = new_data;
	new_node->Next = p->Next;
	new_node->Previous = p;
	p->Next->Previous = new_node;
	p->Next = new_node;
	return 1;
}
int insert_AT(Node* head, int position, ELEMTYPE new_data) {
	Node* new_node = malloc(sizeof(Node));
	if (new_node == NULL) {
		printf("fail");
		return 0;
	}
	new_node->data = new_data;
	Node* p = head;
	for (int i = 0; i < position-1; i++) {
		p = p->Next;
		if (p == head) {
			printf("the position is void");
			return 0;
		}
	}
	new_node->Next = p->Next;
	new_node->Previous = p;
	p->Next->Previous = new_node;
	p->Next = new_node;
	return 1;
}
int delete_AT(Node* head, int position) {
	Node* p = head;
	for (int i = 0; i < position - 1; i++) {
		p = p->Next;
		if (p == head) {
			printf("the position is void");
			return 0;
		}
	}
	Node* del = p->Next;
	if (del == head) {
		printf("Cannot delete head node\n");
		return 0;
	}
	p->Next = del->Next;
	del->Next->Previous = p;
	free(del);
	return 1;
}
int find_data(Node* head, ELEMTYPE data) {
	Node* p = head->Next;
	int pos = 1;
	while (p != head) {
		if (p->data == data) return pos;
		p = p->Next;
		pos++;
	}
	return 0;
}
void for_ward(Node* head) {
	Node* p = head->Next;
	if (p == head) {
		printf("the list is void");
		return ;
	}
	while (p != head) {
		printf("%d\n", p->data);
		p = p->Next;
	}
}
void back_ward(Node* head) {
	Node* p = head->Previous;
	if (p == head) {
		printf("the list is void");
		return;
	}
	while (p != head) {
		printf("%d\n", p->data);
		p = p->Previous;
	}
}