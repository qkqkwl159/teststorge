#include <stdio.h>
#include <stdlib.h>

typedef char* Data;
typedef struct Node{
	Data value;
	struct Node* next;
}Node;


void print_list(Node *a){
	for(Node *curr = a; curr!=NULL;curr = curr->next){
		printf("%s -> ",curr->value);
	}
	printf("\b\b\b   	\n");
}

Node * AllocNewNode(Data value){
	Node *node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->next = NULL;
	return node;
}

void insertNode(Node *head, Data value){
	Node * tmp = AllocNewNode(value);
	tmp->next = head->next;
	tmp->value = value;

	head->next = tmp;
}

void insert_last(Node *head,Node **last ,Data value){
	/*
		 1 마지막에대한 정보가 있을때 마지막에 node를 새로 추가해준다.
			마지막 Node의 정보를 업데이트 해준다.
		 */
	Node *node = AllocNewNode(value);
	(*last)->next = node;
	*last = node;
}

int main(int argc, char *argv[]){
	
	Node * head = AllocNewNode("Mon");
	Node * last = head;
	
	insertNode(head,"Wed");
	insertNode(head,"Wed");
	insertNode(head,"Wed");

	print_list(head);
	return 0;
}

