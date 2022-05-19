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
	printf("\b\b\b	\n");
}

int main(int argc, char *argv[]){

	Node *a = (Node*)malloc(sizeof(Node));
	a->value = 10;
	a->next = NULL;
	
	Node *b = (Node*)malloc(sizeof(Node));
	b->value = 20;
	b->next = NULL;

	Node *c = (Node*)malloc(sizeof(Node));
	c->value = 30;
	c->next = NULL;
	a->next = b;
	b->next = c;
	Node * node = (Node*) malloc (sizeof(Node));
	node->value = 15;
	node->next = NULL;

	Node *curr = a;
	// Node node 추가
	node->next = curr->next;
	curr->next = node;
	//a->next = node;
	//node->next = b;
	// Node b 삭제	
	//node->next = c;
	//b->next = NULL;
	// curr를 이용하여 node를 연결하시오.
	print_list(a);
	return 0;
}
