#include <stdio.h>
#include <stdlib.h>
//#define DEBUG
#include "log.h"


typedef struct Node{
	char* value;
	struct Node *next;
	struct Node *pre;
}Node;

Node* addNewNode(char* value){

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = NULL;
	newNode->pre = NULL;

	return newNode;
}

void insertLast(Node** head, char* value){

	Node* newNode =	addNewNode(value);

	if(*head == NULL){
		*head = newNode;
	}
	else{
		Node* curr = *head;

		while(curr->next != NULL)
			curr = curr->next;

		curr->next = newNode;
		newNode->pre = curr;
	}
}

void insertFirst(Node** head, char* value){

	Node* newNode = addNewNode(value);

	if(*head == NULL)
		*head = newNode;

	else{
		newNode->next = (*head);
		(*head) = newNode;
		newNode->next->pre = newNode;
	}
}

void deleteNode(Node* head,int index){
	Node* curr = head;

	while(curr->next->next != NULL && index > 0){

		index--;
		curr = curr->next;

	}

//	Node* rmNode = curr->next;
//	curr->next = rmNode->next;
//	
//	free(rmNode);
	curr->pre->next = curr->next;
	curr->next->pre = curr->pre;
	free(curr);
}

void deleteLast(Node* head){

	Node* curr =  head;

	while(curr->next->next != NULL)
		curr = curr->next;

	curr->next = NULL;
	free(curr->next);
}

void deleteFirst(Node** head){
	LOG("head : %p , head->next: %p \n\n",*head,(*head)->next);

	*head = (*head)->next;
	(*head)->next = (*head)->next;
	(*head)->pre = NULL;
}


void printList(Node* head){
	
	Node* curr = head;

	while(curr != NULL){

		printf("%s -> ",curr->value);
		curr = curr->next;

	}

	printf("NULL\n");

	//printf("\b\b\b    \n");
}

void printInvertList(Node* head){
	
	Node* curr = head;

	while(curr->next != NULL){

		curr = curr->next;

	}

	Node* tail = curr;
	for(tail = curr; tail != head; tail = tail->pre){
		printf("%s -> ", tail->value);
	}
	printf("%s -> ", tail->value);

	printf("Head\n");

}

int main(int argc, char* argv[]){

	Node* head = NULL;

	insertLast(&head,"Apple");
//	insertLast(&head,"Banana");
//	insertLast(&head,"Durian");
//	printList(head);
//	printInvertList(head);
//
//	deleteNode(head,1);
//	printList(head);
//
//	insertFirst(&head,"3");
//	insertFirst(&head,"2");
//	insertFirst(&head,"1");
//	printList(head);
//	printInvertList(head);
//	
//	deleteLast(head);
//	printList(head);
//
//	deleteFirst(&head);
//	LOG("MAIN : %p \n",head);
	printList(head);

	return 0;
}
