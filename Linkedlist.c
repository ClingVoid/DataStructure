#include<stdio.h>
#include<stdlib.h>
#define ELEMTYPE int
typedef struct node {
	ELEMTYPE data;
	struct node* Next;
}Node;
Node* __init__() {
	Node* head = malloc(sizeof(Node));
	if (head == NULL) {
		perror("malloc");
		return NULL;
	}
	head->Next = NULL;
	return head;
}
int insert_tail(Node* head,ELEMTYPE new_data) {
	Node* new_node = malloc(sizeof(Node));
	if (new_node == NULL) {
		perror("malloc");
		return 0;
	}
	new_node->data = new_data;
	new_node->Next = NULL;
	Node* p = head;
	while (p->Next != NULL) {
		p = p->Next;
	}
	p->Next = new_node;
	return 1;
}
int insert_head(Node* head, ELEMTYPE new_data) {
	Node* new_node = malloc(sizeof(Node));
	if (new_node == NULL) {
		perror("malloc");
		return 0;
	}
	new_node->data = new_data;
	new_node->Next = head->Next;
	head->Next = new_node;
	return 1;
}
int printf_everyone(Node* head) {
	if (head->Next == NULL) {
		printf("The list is Void");
		return 0;
	}
	Node* p = head->Next;
	while (p != NULL) {
		p = p -> Next;
		printf("%d", p->data);
	}
	return 1;
}
int insert_AT(Node* head, int position, ELEMTYPE new_data) {
	Node* new_node = malloc(sizeof(Node));
	if (new_node == NULL) {
		perror("malloc");
		return 0;
	}
	new_node->data = new_data;
	Node* p = head;
	for (int i = 0; i < position - 1; i++) {
		if (p == NULL) {
			printf("the position out range");
			return 0;
		}
		p = p->Next;
	}
	new_node->Next = p->Next;
	p->Next = new_node;
	return 1;
}
int delete_AT(Node * head, int position) {
	if (head->Next == NULL) {
		printf("the list is void");
		return 0;
	}
	Node* p = head;
	for (int i = 0; i < position-1; i++) {
		if (p == NULL) { printf("the position out of range"); return 0; }
		p = p->Next;
	}
	Node* dele = p->Next;
	if(dele==NULL){ printf("the position out of range"); return 0; }
	p->Next = dele->Next;
	free(dele);
	return 1;
	}
int find_data(Node* head,ELEMTYPE data) {
	Node* p = head->Next;
	int count = 1;
	while (p != NULL) {
		if (p->data == data) {
			return count;
		}
		p = p->Next;
		count++;
	}
	return 0;
}
