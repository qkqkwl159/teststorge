#include <stdio.h>
#include <stdlib.h>

typedef int Data;
typedef struct Node{
	struct Node *next;
	struct Node *pre;
	Data value;
}Node;

Node* addNode(Data value){

	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->next = NULL;
	newNode->pre = NULL;
	newNode->value = value;

	return newNode;
}

void insertNode(Node** head,Node** tail, Data value){

	Node* newNode = addNode(value);

	if(*head == NULL){

		*head = newNode;
		*tail = newNode;

	}
	else{
		Node* tmp = *tail;
		tmp->next = newNode;
		*tail = newNode;

		(*tail)->next = *head;
		(*tail)->pre = tmp;
		(*head)->pre = *tail;
	}
}

Data deleteNode(Node* head, int delete_index){

	Node* curr = head;
	while(delete_index > 0){

		delete_index--;
		curr = curr->next;

	}
	curr->pre->next = curr->next;
	curr->next->pre = curr->pre;
	
	return curr->value;

}

void printList(Node* head,Node* tail){

	Node* curr = head;

	while(curr != tail){
		printf("%d -> ",curr->value);
		curr = curr->next;
	}
	printf("%d -> \n",curr->value);
}
/*
void yosepus(int size, int delete_index){

	int Del = delete_index - 1;

	for(int i = 1; i <= size; i++){
		insertNode(&head,&tail,i);
	}



}
*/


int main(int argc, char* argv[]){

	Node* head = NULL;
	Node* tail = NULL;

	for(int i = 1; i < 8; i++){
		insertNode(&head,&tail,i);
	}
	printList(head,tail);

	deleteNode(head,3);
	printList(head,tail);


	return 0;

}
