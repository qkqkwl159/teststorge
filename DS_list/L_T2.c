#include <stdio.h>
#include <stdlib.h>
#define DEBUG
#include "log.h"

typedef int Data;
typedef struct Node{
	Data value;
	struct Node *next;
}Node;

/*
	 insertLadt, insertFirst, insertNode
	 freeList, printList, deleteNode
	 */
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
		LOG("InsertLast\n");
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
		curr->next = newNode;
	}
}
		
void insertNode(Node* head, Data value, int index){
	Node* newNode = addNewNode(value);
	Node* curr = head;
	while(curr != NULL && index > 0){
		index--;
		curr = curr->next;
	}

	newNode->next = curr->next;
	curr->next = newNode;
}

void deleteFirst(Node* head){
		LOG("DELETE \n");
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
		 

void printList(Node* head){
	Node* curr = head->next;
	while(curr != NULL){
		printf("%d -> ",curr->value);
		curr = curr->next;
	}
	printf("\b\b\b     \n");
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

	Node* head = addNewNode(0);;

	insertLast(head,10);
//	insertLast(head,20);
//	insertLast(head,30);
//	insertLast(head,40);
//	insertLast(head,50);
	printList(head);
	deleteLast(head);

	
	printList(head);
	freeList(head);

	return 0;
}
