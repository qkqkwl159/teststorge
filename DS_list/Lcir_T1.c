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

Node* deleteNode(Node** head, Node** tail, Node* node, int delete_term){


	Node* curr = node;
	
	
	if(*head == *tail){

		*head = NULL;
		*tail = NULL;
		return curr;
		
	}
	while(delete_term != 1){

		delete_term--;
		curr = curr->next;

	}
	curr->pre->next = curr->next;
	curr->next->pre = curr->pre;


	if(curr == *tail)
		*tail = curr->pre;
	if(curr == *head)
		*head = curr->next;
	
	return curr;

}


void printList(Node* head,Node* tail){

	if(head == NULL){
		printf("NULL\n");
		return;
	}
		
	Node* curr = head;

	while(curr != tail){
		printf("%d -> ",curr->value);
		curr = curr->next;
	}
	printf("%d -> \n",curr->value);
}

void printarr(Data *arr,int size){
	for(int i = 0; i<size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void yosupus(Node* head, Node* tail, int head_count, int term){

	Data *arr = (Data*)malloc(sizeof(Data) * head_count);
	int count = 0;

	for(int i = 1; i < head_count + 1; i++)
		insertNode(&head,&tail,i);

	Node* delRtn = deleteNode(&head,&tail,head,term);
	arr[count++] = delRtn->value;

	for(int i = 0; i<(head_count -1 );i++){
		
		delRtn = deleteNode(&head,&tail,delRtn->next,term);
		arr[count++] = delRtn->value;
		
	}
	printarr(arr,head_count);
}


int main(int argc, char* argv[]){

	Node* head = NULL;
	Node* tail = NULL;
	int count = 0;

	int N, K;
	scanf("%d %d",&N,&K);


	yosupus(head,tail,N,K);
	return 0;

}
