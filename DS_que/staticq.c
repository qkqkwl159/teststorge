#include <stdio.h>
#include <stdlib.h>
#define DEBUG
#include "log.h"
#define MAX_SIZE 5
/*
	 init(), enque(), deque(), isfull(), isempty()
	 */

typedef char Data;
typedef struct{
	int front;
	int rear;
	Data arr[MAX_SIZE];
}que;

void init(que *q){
	q->front = 0;
	q->rear = 0;
}

int isfull(que *q){
	return (q->rear == MAX_SIZE);
}

int isempty(que *q){
	return (q->front == q->rear);
}

void enque(que *q, Data item){
	if(isfull(q)){
		printf("Full\n");
		return;
	}
	q->arr[q->rear++] = item;
}

Data deque(que *q){
	if(isempty(q)){
		printf("Empty\n");
		return 0;
	}
	LOG("DEQUE\n");
	return q->arr[q->front++];
}

int main(int argc, char *argv[]){

	que q;
	Data inputData;

	init(&q);

	while(!isfull(&q)){
		scanf("%s",&inputData);
		enque(&q,inputData);
		LOG("ENQUE\n");

	}
	while(!isempty(&q)){
		printf("\n%s\n",deque(&q));
	}




	return 0;
}
