#include <stdio.h>
#include <stdlib.h>
#define DEBUG
#include "log.h"

/*
	 insertLast, insertFirst, insertNode,
	 freeList, printList, addNewNode,
	 deleteLast, deleteFirst, deleteNode
	 */

typedef char* Data;
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

void insertFirst(Node* head,Data value){
	Node* newNode = addNewNode(value);
	newNode->next = head->next;

	head->next = newNode;
}

void insertLast(Node* head,Data value){
	if(head->next == NULL){
		Node* newNode = addNewNode(value);
		newNode->next = head->next;

		head->next = newNode;
	}
	else{
		Node* curr = head;
		while(curr->next != NULL){
			curr = curr->next;
		}
		Node* newNode = addNewNode(value);
		newNode->next = curr->next;

		curr->next = newNode;
	}
}

void insertNode(Node* head, Data value,int index){
	Node* curr = head;
	Node* newNode = addNewNode(value);
	while(curr != NULL && index > 0){
		index--;
		curr = curr->next;
	}

	newNode->next = curr->next;
	curr->next = newNode;
}

void deleteFirst(Node* head){
	Node* rmNode = head->next;
	if(rmNode == NULL){
		printf("List Empty\n");
		return;
	}
	head->next = rmNode->next;
	free(rmNode);
}

void deleteLast(Node* head){
	Node* curr = head;
	while(curr->next->next != NULL){
		curr = curr->next;
	}
	Node* rmNode = curr->next;
	curr->next = rmNode->next;
	free(rmNode);
}

void deleteNode(Node* head,int index){
	Node* curr = head;
	Node* rmNode;
	while(curr->next->next != NULL && index > 0){
		index--;
		curr = curr->next;
	}
	rmNode = curr->next;
	curr->next = rmNode->next;
	free(rmNode);
}

void printList(Node* head){
	Node* curr = head->next;
	while(curr != NULL){
		printf("%s -> ",curr->value);
		curr = curr->next;
	}
	printf("\b\b\b    \n");
}

void freeList(Node* head){
	Node* curr = head;
	Node* next;
	while(curr != NULL){
		next = curr->next;
		free(curr);
		curr = next;
	}
}

int main(int argc, char* argv[]){

	Node* head = addNewNode(0);

	insertLast(head,"Tue");
	insertLast(head,"Fri");
	insertLast(head,"Sat");
	insertFirst(head,"Mon");
	insertNode(head,"Wed",2);
	insertNode(head,"Thu",3);
	insertLast(head,"Sun");
	printList(head);

	LOG("======= INSERT ======\n");

	deleteFirst(head);
	deleteFirst(head);
	deleteLast(head);
	deleteLast(head);
	deleteNode(head,2);


	printList(head);
	freeList(head);
	return 0;
}
