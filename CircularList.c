#include<stdio.h>
#include<stdlib.h>
#define elemtype int
typedef struct node {
	elemtype data;
	struct node* Next;
}Node;
Node* initlist(void) {
	Node* list;
 list = malloc(sizeof(Node));
	if (list ==NULL) {
		perror("malloc");
		return NULL;
	}
	list->Next = list;
	return list;
}
int insertend(Node* list,elemtype element) {
	Node* new_list = malloc(sizeof(Node));
	if (new_list == NULL) {
		perror("malloc");
		return 0;
	}
	new_list->data = element;
	Node* head = list;
	while (list->Next!=head) {
		list = list->Next;
	}
	new_list->Next = list->Next;
	list->Next = new_list;
	return 1;
}
int insertstart(Node* list, elemtype element) {
	Node* new_list = malloc(sizeof(Node));
	if (new_list == NULL) {
		perror("malloc");
		return 0;
	}
	new_list->data = element;
	new_list->Next = list->Next;
	list->Next = new_list;
}
int insertAT(Node* list, int position, elemtype element) {
	for (int i = 0; i < position-1; i++) {
		list = list->Next;
	}
	Node* new_list = malloc(sizeof(Node));
	if (new_list == NULL) {
		perror("malloc");
		return 0;
	}
	new_list->Next = list->Next;
	list->Next = new_list;
	return 1;
}
int deletelist(Node* list, int position) {
	if (list->Next == list) {
		return 0;
	}
	for (int i = 0; i < position-1; i++) {
		list = list->Next;
		if (list->Next == list) {
			return 0;
		}
	}
	Node* temporary;
	temporary = list->Next;
	list->Next = temporary->Next;
	free(temporary);
	return 1;
}
int printlist(Node* list) {
	Node* temporary;
	temporary = list->Next;
	while (temporary !=list) {
		printf("%d", temporary->data);
		temporary = temporary->Next;
	}
	return 1;
}
int find(Node* list,elemtype element) {
	int i = 0;
	Node* temporary = list->Next;
	while (temporary != list) {
		i++;
		if (element == temporary->data) {
			return i;
		}
	}
	return 0;

}
int lengh(Node* list) {
	int i = 0;
	Node* temporary = list->Next;
	while (temporary != list) {
		i++;
		temporary = temporary->Next;
	}
	return i;
}
int main()
{
	Node* head;
	head = initlist();
	insertend(head, 40);
	insertend(head, 50);
	printlist(head);
	return 0;
}