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
/*
Node* node_return(Node *node,int nodevalue){

	Node *node = (Node*)malloc(sizeof(Node));
	node->next = NULL;
	node->value = nodevalue;
	head->next = node;
}
*/
int main(int argc, char* argv[]){

	Node *head = (Node*)malloc(sizeof(Node));
	head->value = 100;
	
	Node *no1 = (Node*)malloc(sizeof(Node));
	head->next = no1;
	no1->value = 200;
	
	Node *no2 = (Node*)malloc(sizeof(Node));
	no1->next = no2;
	no2->value = 300;



	printf_list(head);
	free_list(head);

	return 0;
}
/* for반복문에서 반복조건을 NULL일때까지가 아니라 상수로 
	 size를 받아온후 size만큼 반복시켜 node에 값을 저장시킨다
	 */
