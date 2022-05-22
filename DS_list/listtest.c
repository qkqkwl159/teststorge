#include <stdio.h>
#include <stdlib.h>

typedef int Data;
typedef struct Node{
	Data value;
	struct Node *next;
}Node;

Node* addNode(Node* newNode,Data value){
	newNode = (Node*)malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = NULL;

	return newNode;
}

void insertFirst(Node* head,Data value){
	Node* newNode = addNode(newNode,value);
	newNode->next = head->next;

	head->next = newNode;
}

void insertLast(Node* head,Data value){
	if(head->next == NULL){
		Node* newNode = addNode(newNode,value);
		newNode->next = head->next;
		
		head->next = newNode;
	}
	else{
		Node* cur = head;
		while(cur->next != NULL){
			cur = cur->next;
		}
		Node* newNode = addNode(newNode,value);
		cur->next = newNode;
	}
}

void insertNode(Node* head,Data value,int index){
	Node* cur = head;
	Node* newNode = addNode(newNode,value);
	while(cur != NULL && index > 0){
		index--;
		cur = cur->next;
	}
	newNode->next = cur->next;
	cur->next = newNode;
}

void printList(Node* head){
	for(Node* cur = head->next; cur != NULL; cur= cur->next){
		printf("%d -> ", cur->value);
	}
	printf("\b\b\b     \n");
}

void freeList(Node* head){
	Node* cur = head;
	Node* next;
	while(cur != NULL){
		next = cur->next;
		free(cur);
		cur = next;
	}
}
int main(int argc, char* argv[]){

	Node* head = addNode(head,0);
	
	insertLast(head,10);
	insertLast(head,20);
	insertLast(head,30);
	insertLast(head,40);
	

	insertFirst(head,50);

	insertNode(head,60,2);
	insertNode(head,70,6);

	printList(head);
	freeList(head);




	return 0;
}
