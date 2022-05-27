#include <stdio.h>
#include <stdlib.h>

/* insertNode, deleteNode
	 addNode,
	 */

typedef char* Data;

typedef struct Node{
	struct Node *next;
	struct Node *prev;
	Data value;
}Node;


Node* addNode(Data value){

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->value = value;

	return newNode;
}

void insertNode(Node** head, Node** tail,Data value){

	Node* newNode = addNode(value);

	//노드가 아무것도없다면 노드를 그냥 추가.
	if(*head == NULL){

		*head = newNode;
		*tail = *head;

	}
	else{

		Node* tmp = *tail;
		tmp->next = newNode;
		*tail = newNode;
		(*tail)->prev = tmp;

		//끝과 시작을 이어주는 코드
		(*head)->prev = *tail;
		(*tail)->next = *head;

	}
}

void deleteNode(Node** head, Node**tail){

	Node* rmNode = (*tail);
	(*tail) = rmNode->prev;
	(*tail)->next = (*head);
	(*head)->prev = (*tail);

	free(rmNode);

}

void freeList(Node* head, Node* tail){

	Node* curr = head;
	Node* tmp;
	while(curr != tail){
		printf("%s Freed!\n",curr->value);
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	printf("%s Freed!\n",curr->value);
	free(curr);
}


void printList(Node* head,Node* tail){

	Node* curr = head;

	while(curr != tail){
		printf("%s -> ",curr->value);
		curr = curr->next;
	}
	printf("%s ->\n",curr->value);

}

void printInverte(Node* head, Node* tail){

	Node* curr = tail;

	while(curr != head){

		printf("%s -> ",curr->value);
		curr = curr->prev;

	}
	printf("%s -> \n",curr->value);

}
int main(int argc, char* argv[]){

	Node* head = NULL;
	Node* tail = NULL;

	insertNode(&head,&tail,"Hello");
	insertNode(&head,&tail,"world");
	insertNode(&head,&tail,"guys");
	printList(head,tail);
	printInverte(head,tail);

	deleteNode(&head,&tail);
	deleteNode(&head,&tail);
	printList(head,tail);

	freeList(head,tail);
	return 0;
}
