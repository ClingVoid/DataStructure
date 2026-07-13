#include<stdio.h>
#include<stdlib.h>
#define ELEMTYPE int
typedef struct node {
	ELEMTYPE data;
	struct node* Next;
}Node;
int __init__(Node** head) {
	*head = malloc(sizeof(Node));
	if (*head == NULL) {
		perror("malloc");
		return 0;
	}
	(*head)->Next = NULL;
	return 1;
}
int enqueue(Node* head, ELEMTYPE new_data) {
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
int dequeue(Node* head) {
	if (head->Next == NULL) {
		printf("the list is void");
		return 0;
	}
	Node* dele = head->Next;
	head->Next = dele->Next;
	ELEMTYPE data = dele->data;
	free(dele);
	return data;
}
int display(Node* head) {
	if (head->Next == NULL) {
		printf("The list is Void");
		return 0;
	}
	Node* p = head->Next;
	while (p != NULL) {
		printf("%d", p->data);
		p = p->Next;
	}
	return 1;
}
