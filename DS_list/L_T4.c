#include <stdio.h>
#include <stdlib.h>
#define DEBUG
#include "log.h"

/*
	 printList, freeList, addNewNode,
	 insertLast, insertFirst, insertNode,
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

void insertFirst(Node* head, Data value){
	Node* newNode = addNewNode(value);
	newNode->next = head->next;

	head->next = newNode;
}


void insertLast(Node* head, Data value){
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

void insertNode(Node* head, Data value, int index){
	Node* curr = head;
	Node* newNode = addNewNode(value);
	while(curr != NULL && index > 0){
		index--;
		curr = curr->next;
	}
	newNode->next = curr->next;
	curr->next = newNode;
}

//void deleteFirst(Node* head){
//	Node* rmNode = head->next;
//	head->next = rmNode->next;
//
//	free(rmNode);
//}

void deleteFirst(Node* head){
	Node* rmNode = head->next;
	head->next = rmNode->next;
	free(rmNode);
}

//void deleteLast(Node* head){
//	Node* curr = head;
//	while(curr->next->next != NULL){
//		curr = curr->next;
//	}
//	Node* rmNode = curr->next;
//	curr->next = rmNode->next;
//	free(rmNode);
//}

void deleteLast(Node* head){
	Node* curr = head;
	while(curr->next->next != NULL){
		curr = curr->next;
	}
	Node* rmNode = curr->next;
	curr->next = rmNode->next;
	free(rmNode);
}

//void deleteNode(Node* head,int index){
//	Node* curr = head;
//	while(curr->next->next != NULL && index > 0){
//		index--;
//		curr = curr->next;
//	}
//	Node* rmNode = curr->next;
//	curr->next = rmNode->next;
//	free(rmNode);
//}

void deleteNode(Node* head, int index){
	Node* curr = head;
	while(curr->next->next != NULL && index > 0){
		index--;
		curr = curr->next;
	}
	Node* rmNode = curr->next;
	curr->next = rmNode->next;
	free(rmNode);
}



int main(int argc, char* argv[]){

	Node* head = addNewNode(NULL);

	insertLast(head,"Hello");
	insertFirst(head,"Computer");
	insertNode(head,"DataStrcut",1);
	printList(head);
	LOG("INSERT ========\n\n");

	deleteFirst(head);
	printList(head);
	LOG("DELFIRST =========\n\n");
	insertFirst(head,"Computer");

	deleteLast(head);
	printList(head);
	LOG("DELLAST =========\n\n");
	insertLast(head,"Hello");

	deleteNode(head,1);
	printList(head);
	LOG("DELINDEX : 1=========\n\n");

	freeList(head);

	return 0;

}
