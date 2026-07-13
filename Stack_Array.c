#include<stdio.h>
#include<stdlib.h>
#define ELEMTYPE int
#define MAXSIZE 100
typedef struct stack {
	ELEMTYPE data[MAXSIZE];
	int top;
}Stack;
void __init__(Stack** head) {
	*head = malloc(sizeof(Stack));
	if (*head == NULL) {
		printf("fail");
		return;
	}
	(*head)->top = 0;
}
int push(Stack* head, ELEMTYPE data) {
	if (head->top >= MAXSIZE) {
		printf("it's stuff full");
		return 0;
	}
	head->data[head->top++] = data;
	return 1;
}
int pop(Stack* head) {
	if (head->top <= 0) {
		printf("void");
		return 0;
	}
	ELEMTYPE data = head->data[--head->top];
	return data;
}
void disply(Stack* head) {
	for (int i = head->top-1; i >= 0; i--) {
		ELEMTYPE data = head->data[i];
		printf("%d\n", data);
	}
}