#include<stdio.h>
#define ELEMTYPE int
#define MAXSIZE 10
typedef struct queue {
	ELEMTYPE data[MAXSIZE];
	int front;
	int rear;
}Queue;
void __init__(Queue* head) {
	head->front = 0;
	head->rear = 0;
}
int enqueue(Queue* head,ELEMTYPE data) {
	if ((head->rear + 1) % MAXSIZE == head->front) {
		printf("it's stuff full");
		return 0;
	}
	head->data[head->rear] = data;
	head->rear=(head->rear + 1) % MAXSIZE;
	return 1;
}
int dequeue(Queue* head) {
	if (head->front == head->rear) {
		printf("it's void");
		return -1;
	}
	ELEMTYPE data = head->data[head->front];
	head->front=(head->front + 1) % MAXSIZE;
	return data;
}
int display(Queue* head) {
	int i = head->front;
	while (i != head->rear) {
		printf("%d\n", head->data[i]);
		i = (i + 1) % MAXSIZE;
	}
	return 0;
}