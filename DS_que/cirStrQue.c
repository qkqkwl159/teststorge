#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG
#include "log.h"
#define MAX_SIZE 5 

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
	return (((q->rear + 1) % MAX_SIZE) == q->front);
}

int isempty(que *q){
	return (q->front == q->rear);
}

void enque(que *q, Data item){
	if(isfull(q)){
		printf("Full\n");
		return;
	}
	q->rear = (q->rear +1 ) % MAX_SIZE;
	q->arr[q->rear] = item;
}

Data deque(que *q){
	if(isempty(q)){
		printf("Empty\n");
		return NULL;
	}
	q->front = (q->front + 1) % MAX_SIZE;
	return q->arr[q->front];
}

Data peek(que *q){
	return q->arr[q->front];
}


int main(int argc, char *argv[]){

	que q;
	init(&q);

	while(!isfull(&q)){
		Data str = (Data)malloc(sizeof(char));
		scanf("%s",str);
		enque(&q,str);
		LOG("REAR : %d\n",q.rear);
	}

	while(!isempty(&q)){
		printf("%s\n",deque(&q));
	}

	return 0;
}
