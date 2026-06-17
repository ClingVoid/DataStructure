#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define elemtype int
typedef struct node {
	elemtype data;
	struct node* Next;
}Node;
Node* initlist() {
	Node* head = (Node*)malloc(sizeof(Node));
	if (head == NULL) {
		perror("malloc");
		return NULL;
	}
	head->Next = NULL;
	return head;
}
int insertlist_end(Node* list, elemtype element) {
	Node* new_list = (Node*)malloc(sizeof(Node));
	while (list->Next != NULL) {
		list = list->Next;
	}
	list->Next = new_list;
	new_list->Next= NULL;
	new_list->data = element;
	return 1;
}
int insertlist_start(Node* list, elemtype element) {
	Node* new_list = malloc(sizeof(Node));
	new_list->Next = list->Next;
	list->Next = new_list;
	new_list->data = element;
	return 1;
}
void printlist(Node* list) {
	Node* p = list->Next;
	while (p != NULL) {
		printf("%d\n", p->data);
		p = p->Next;
	}
}
int insertAT(Node* list, int position, elemtype element) {
	for (int i = 0; i < position-1; i++) {
		list = list->Next;
		if (list == NULL) {
			return 0;
		}
	}
	Node* new_list = malloc(sizeof(Node));
	new_list->data = element;
	new_list->Next = list->Next;
	list->Next = new_list;
	return 1;
}
int deleteAT(Node* list, int position) {
	for (int i = 0; i < position - 1; i++) {
		list = list->Next;
		if (list == NULL) {
			return 0;
		}
	}
	Node* tem = list->Next;
		list->Next = tem->Next;
		free(tem);
		return 1;
}
int findlist(Node* list, elemtype element) {
	int i = 0;
	list = list->Next;
	while (list) {
		i++;
		if (list->data == element) {
			return i;
		}
		list = list->Next;
	}
	return 0;
}
int main()
{
	elemtype a = 40;
	Node* head = initlist();
	insertlist_end(head, a);
	insertlist_end(head, 80);
	insertlist_end(head, 90);
	insertlist_end(head, 100);
	insertAT(head, 2, 70);
	deleteAT(head, 2);
	printlist(head);
	int c=findlist(head, 40);
	printf("%d", c);
	return 0;
}