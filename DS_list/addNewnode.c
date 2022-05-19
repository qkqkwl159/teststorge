#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
	int value;
	struct Node* next;
}Node;


void print_list(Node *a){
	for(Node *curr = a; curr!=NULL;curr = curr->next){
		printf("%d -> ",curr->value);
	}
	printf("\b\b\b   	\n");
}

Node * AllocNewNode(int value){
	Node *node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->next = NULL;
	return node;
}
void insert_last(Node *head,Node **last ,int value){
	/*
		 1 마지막에대한 정보가 있을때 마지막에 node를 새로 추가해준다.
			마지막 Node의 정보를 업데이트 해준다.
		 */
	Node *node = AllocNewNode(value);
	(*last)->next = node;
	*last = node;
}

int main(int argc, char *argv[]){
	Node * head = AllocNewNode(10);
	Node * last = head;
	
	for(int i = 20;i < 100; i=i+10){
		insert_last(head, &last, i);
	}

	print_list(head);
	return 0;
}

