#include <stdio.h>
#include <stdlib.h>

typedef char* Data;
typedef struct Node{
	Data value;
	struct Node *next;
	struct Node *pre;
}Node;


Node* addNode(Data value){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = NULL;
	newNode->pre = NULL;

	return newNode;
}

void insertFirst(Node** head,Data value){

	Node* newNode = addNode(value);

	if(*head == NULL)
		*head = newNode;

	else{
		newNode->next = (*head);
		*head = newNode;
		newNode->next->pre = newNode;
	}
}

void insertLast(Node** head,Data value){
	
	Node* newNode = addNode(value);

	if(*head == NULL)
		*head = newNode;
	
	else{
		Node* curr = *head;

		while(curr->next != NULL)
			curr = curr->next;

		curr->next = newNode;
		newNode->pre = curr;
	}
}

void printList(Node* head){

	for(Node* curr = head; curr != NULL; curr = curr->next)
		printf("%s -> ", curr->value);

	printf("NULL\n");
}

void printReverse(Node* head){

	Node* curr = head;
	while(curr->next != NULL)
		curr = curr->next;


	Node* reverse = curr;

	while(reverse !=  head){

		printf("%s -> ", reverse->value);
		reverse = reverse->pre;

	}

	printf("%s -> ", reverse->value);
	printf("HEAD\n");

}


int main(int argc, char* argv[]){

	Node* head = NULL;

	insertFirst(&head,"hello");
	insertLast(&head,"World");

	printList(head);
	printReverse(head);

	return 0;
}
