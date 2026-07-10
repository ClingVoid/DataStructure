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
    (*head)->Next = head;
    return 1;
}
int printf_every(Node* head) {
    Node* p = head->Next;
    if (head->Next != head) {
        while (p != head) {
            printf("%d\n", p->data);
            p = p->Next;
        }
        return 1;
    }
    printf("the circularlist is Void");
    return 0;
}
int insert_tail(Node* head, ELEMTYPE new_data) {
    Node* p = head->Next;
    while (p->Next != head) {
        p = p->Next;
    }
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        perror("malloc");
        return 0;
    }
    new_node->data = new_data;
    new_node->Next = head;
    p->Next = new_node;
}
int insert_head(Node* head, ELEMTYPE new_data) {
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        perror("malloc");
        return 0;
    }
    new_node->data = new_data;
    Node* p = head->Next;
    new_node->Next = p;
    head->Next = new_node;
    return 1;
}
int insert_AT(Node* head, int position, ELEMTYPE new_data) {
    if (position < 1) {
        printf("Invalid position\n");
        return 0;
    }
    Node* p = head;
    for (int i = 0; i < position - 1; i++) {
        if (p->Next == head) {
            printf("Position out of range\n");
            return 0;
        }
        p = p->Next;
    }
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        perror("malloc");
        return 0;
    }
    new_node->data = new_data;
    new_node->Next = p->Next;
    p->Next = new_node;
    return 1;
}

int delete_AT(Node* head, int position) {
    if (head->Next == head) {
        printf("The list is void\n");
        return 0;
    }
    Node* p = head;
    for (int i = 0; i < position - 1; i++) {
        if (p->Next == head) {
            printf("Position out of range\n");
            return 0;
        }
        p = p->Next;
    }
    Node* dele = p->Next;
    if (dele == head) {
        printf("Position out of range\n");
        return 0;
    }
    p->Next = dele->Next;
    free(dele);
    return 1;
}

int find_data(Node* head, ELEMTYPE data) {
    Node* p = head->Next;
    int count = 1;
    while (p != head) {
        if (p->data == data) {
            return count;
        }
        p = p->Next;
        count++;
    }
    return 0;
}
