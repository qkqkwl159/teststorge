#include <stdio.h>
#include <stdlib.h>

/*
	 freeNode, printNode, addNewNode
	 insert First,insertLadt, insertNode
	 deleteFirst, deleteLast, deleteNode
	 */

typedef int Data;
typedef struct Node{
	Data value;
	struct Node *next;
}Node;

Node* addNewNode(Data value){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = NULL;

	return newNode;
}

void freeNode(Node* head){
	Node* curr = head;
	Node* next;
	while(curr != NULL){
		next = curr->next;
		free(curr);
		curr = next;
	}
}

void printList(Node* head){
	Node* curr = head;
	while(curr != NULL){
		printf("%d -> ",curr->value);
		curr = curr->next;
	}
	printf("\b\b\b    \n");
}

void insertFirst(Node* head, Data value){
	Node* newNode = addNewNode(value);
	newNode->next = head->next;
	head->next = newNode;
}

void insertLast(Node* head, Data value){
	Node* curr = head;
	while(curr->next != NULL){
		curr = curr->next;
	}
	Node* newNode = addNewNode(value);
	newNode->next = curr->next;
	curr->next = newNode;
}

void insertNode(Node* head, Data value, int index){
	Node* curr = head;
	while(curr != NULL && index > 0){
		index--;
		curr = curr->next;
	}
	Node* newNode = addNewNode(value);
	newNode->next = curr->next;
	curr->next = newNode;
}

int main(int argc, char* argv[]){


	Node* head = addNewNode(0);

	insertFirst(head,5);
	insertLast(head,10);
	insertNode(head,8,1);
	printList(head);
	freeNode(head);

	return 0;
}
