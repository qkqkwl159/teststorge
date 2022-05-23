#include <stdio.h>
#include <stdlib.h>
#define DEBUG
#include "log.h"

typedef char* Data;
typedef struct Node{
	Data data;
	struct Node *next;
}Node;

Node* CreateNode(Data data){

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}

void insertLast(Node** head, Data data){

	Node* newNode = CreateNode(data);

	if(*head == NULL) *head = newNode;
	
	else{

		Node* tail = *head;

		while(tail->next != NULL)
			tail = tail->next;

		tail->next = newNode;
	}
}
/*
	 void insertNode(Node* head,Data data,int index){
			Node* newNode = CreateNode(data);
			Node* curr = head;
			while(curr != NULL && index>0){
				index--;
				curr = curr->next;
				}
			newNode->next = curr->next;
			curr->next = newNode;
	 }



	 */

void insertAfter(Node** head,Data comparison, Data data){
	
	 Node* newNode = CreateNode(data);

	 Node* curr = *head;

	 while(curr != NULL && (comparison != curr->data)){
		 curr = curr ->next;
	 }

	 if(curr == NULL){

		 printf("Insert failed (%s does not exist)\n",comparison);
		 return;

	 }

	 newNode->next = curr->next;
	 curr->next = newNode;
}

void printList(Node* curr){
	while(curr != NULL){

		printf("%s -> ",curr->data);
		curr = curr->next;
	}
	printf("\b\b\b    \n");
}	

void freeList(Node* curr){
	Node* next;
	printf("\n");
	while(curr != NULL){
		printf("%s freed\n", curr->data);
		next = curr->next;
		free(curr);
		curr = next;
	}
}


int main(int argc, char* argv[]){

	Node* head = NULL;

	insertLast(&head,"Apple"); printList(head);
	insertLast(&head,"Durian"); printList(head);
	insertAfter(&head,"Apple","Banana"); printList(head);
	insertAfter(&head,"Tomato","Grape"); printList(head);
	insertAfter(&head,"Banana","Carrot"); printList(head);

	
	freeList(head);

	return 0;
}
