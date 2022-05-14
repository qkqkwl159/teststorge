#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG
#include "log.h"
#define MAX_SIZE 3 

typedef char* Data;

typedef struct{
	int front;
	int rear;
	Data *arr;
}que;

void init(que *q){
	q->front = 0;
	q->rear = 0;
	q->arr = (Data*)malloc(sizeof(Data) * MAX_SIZE);
}

int isfull(que *q){
	return (q->rear == MAX_SIZE);
}

int isempty(que *q){
	return (q->rear == q->front);
}

void enque(que *q,Data item){
	if(isfull(q)){
		printf("Full\n");
		return;
	}
	q->arr[q->rear++] = item;
}

Data deque(que *q){
	if(isempty(q)){
		printf("Empty\n");
		return NULL;
	}
	LOG("ARR[%d] ITEM : %s \n",q->front,q->arr[q->front]);
	return q->arr[q->front++];
}

Data peek(que *q){
	return q->arr[q->front];
}
int main(int argc, char *argv[]){

	que q;
	init(&q);

	for(int i = 0;i<MAX_SIZE;i++){
		Data str = (Data)malloc(sizeof(char));
		scanf("%s",str);
		enque(&q,str);
		LOG("\nARR[%d] ITEM : %s \n\n",q.rear-1,q.arr[q.rear-1]);
	}
	printf("\n%s\n",deque(&q));
	printf("\n%s\n",deque(&q));
	printf("\n%s\n",deque(&q));
	printf("\n%s\n",deque(&q));




	return 0;
}
