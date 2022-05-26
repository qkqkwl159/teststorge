#include <stdio.h>
#include <stdlib.h>

/*
	 insertFirst(), insertLast(), deleteFirst(), deleteLast()
	 printList(), printInvert()
	 addNode()

	 */

typedef char* Data;
typedef struct Node{
	struct Node *next;
	struct Node *pre;
	Data value;
}Node;

Node* addNode(Data value){

	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->value = value;
	newNode->next = NULL;
	newNode->pre = NULL;

	return newNode;
}

void insertFirst(Node** head, Data value){

	Node* newNode = addNode(value);

	if(*head == NULL)
		*head = newNode;

	else{

		newNode->next = *head;
		*head = newNode;
		newNode->next->pre = newNode;

	}
}

void insertLast(Node** head, Data value){

	Node* newNode = addNode(value);

	if(*head == NULL)
		*head = newNode;

	else{

		Node* curr = *head;
		for(curr = *head; curr->next != NULL; curr = curr->next);

		curr->next = newNode;
		newNode->pre = curr;

	}

}

void printList(Node* head){

	for(Node* curr = head; curr != NULL; curr = curr->next)
		printf("| %s | -> ",curr->value);

	printf("| NULL |\n");

}

void printInverte(Node* head){

	Node* curr = head;

	while(curr->next != NULL)
		curr = curr->next;

	Node* tail = curr;

	while(tail != NULL){
		printf("| %s | -> ",tail->value);
		tail = tail->pre;
	}

	printf("| HEAD |\n");

}

void deleteFirst(Node** head){

	*head = (*head)->next;
	(*head)->pre = NULL;

}

void deleteLast(Node* head){

	Node* curr = head;

	while(curr->next->next != NULL)
		curr = curr->next;

	curr->next = NULL;

}

void insertAfter(Node* head, Data find_value, Data insert_value){

	Node* curr = head;
	while(curr->value != find_value && curr != NULL)
		curr = curr->next;
	
	Node* newNode = addNode(insert_value);

	newNode->next = curr->next;
	curr->next->pre = newNode;

	curr->next = newNode;
	newNode->pre = curr;


}

int main(int argc, char* argv[]){

	Node* head = NULL;
	Node* tail = NULL;

	insertLast(&head,"1");
	insertLast(&head,"2");
	insertLast(&head,"3");
	printList(head);
	printInverte(head);

	deleteFirst(&head);
	printList(head);

	deleteLast(head);
	printList(head);

	insertLast(&head,"Lion");
	insertLast(&head,"Tiger");
	insertLast(&head,"Whale");
	printList(head);

	insertAfter(head,"Lion","Cat");
	printList(head);


	return 0;
}
