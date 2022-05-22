#include <stdio.h>
#include <stdlib.h>

typedef int Data;
typedef struct Node{
	Data value;
	struct Node *next;
}Node;

Node* addNode(Node* head,Data value){

	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->next = NULL;

	return node;
}

void printList(Node *head){
	for(Node *curr = head->next; curr != NULL; curr = curr->next){
		printf("%d -> ",curr->value);
	}
	printf("\b\b\b    \n");
}
//선택 위치에 노드 추가
void insertAfter(Node *cur, Data value){
	Node *newNode = addNode(newNode,value);
	newNode->next = cur->next;
	cur->next = newNode;
}

//전달 받은 해당 인덱스의 Node를 반환
Node* getNode(Node *head,Data index){
	Node *cur = head;
	while(cur->next != NULL && index > 0){
		index--;
		cur = cur->next;
	}
	return cur;
}

void insertNode(Node* head, Data value, int index){
	Node *cur = head;
	Node *newNode = addNode(newNode,value);
	while(cur->next != NULL && index > 0){
		index --;
		cur = cur->next;
	}

	newNode->next = cur->next;
	cur->next = newNode;

}
//head의 바로 다음에 Node추가
void insertFirst(Node *head,Data value){
	
	Node *node = addNode(node,value);
	node->next = head->next;

	head->next = node;
}

//List의 끝에 Node추가 
void insertLast(Node *head,Data value){
	if(head->next == NULL){
		Node *node = addNode(node,value);
		node->next = head->next;

		head->next = node;
	}
	else
	{
		Node *cur = head;
		while(cur->next != NULL){
			cur = cur->next;
		}
		Node *node = addNode(node,value);

		cur->next = node;
	}
}


//List들의 Node free()
void freeList(Node *head){
	Node *cur = head;
	Node *next;
	while(cur != NULL){
		next = cur->next;
		free(cur);
		cur = next;
	}
}

int main(int argc, char*argv[]){

	Node* head = addNode(head,0); 
	Node* tmp;

	insertLast(head,0);
	insertFirst(head,10);
	insertLast(head,20);
	insertFirst(head,30);

//	tmp = getNode(head,3);
//	insertAfter(tmp,40);
	insertNode(head,40,2);
	

	printList(head);

	freeList(head);
	return 0;
}
