#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int value;
	struct Node *next;
}Node;

void printf_list(Node *head){
	//for(int i = 0; i< N ; i++);
	for(Node* curr = head; curr != NULL; curr = curr->next){
		printf("%d -> ", curr->value);
	}
	printf("\n");
}

void free_list(Node *head){
}
//Quiz*Key
Node* node_return(Node *node,int nodevalue){

	Node *node = (Node*)malloc(sizeof(Node));
	node->next = NULL;
	node->value = nodevalue;
	head->next = node;
}
int main(int argc, char* argv[]){


	Node *head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	head->value = 100;

	Node *second = (Node*)malloc(sizeof(Node));
	second->next = NULL;
	second->value = 200;
	head->next = second;

	Node *third = (Node*)malloc(sizeof(Node));
	third->next = NULL;
	third->value = 300;
	second->next = third;

	Node *forth = (Node*)malloc(sizeof(Node));
	forth->next = NULL;
	forth->value = 400;
	third->next = forth;

	printf_list(head);
	free_list(head);

	return 0;
}
