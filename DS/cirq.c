#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG
#include "log.h"

typedef int Data;
typedef struct{
	int front;
	int rear;
	int queSize;
	Data *arr;
}que;

void init(que *q, int max_size){
	q->arr = (Data*)malloc(sizeof(Data) * max_size);
	q->front = 0;
	q->rear = 0;
	q->queSize = max_size;
}

int isfull(que *q){
	return ((q->rear + 1 ) % q->queSize == q->front);
}

int isempty(que *q){
	return (q->front == q->rear);
}

void enque(que *q,Data item){
	if(isfull(q)){
		printf("Error!\n");
		return;
	}
	q->rear = (q->rear + 1) % q->queSize;
	q->arr[q->rear] = item;
}

Data deque(que *q){
	if(isempty(q)){
		printf("Empty!\n");
		return 0;
	}
	q->front = (q->front + 1) % q->queSize;
	return q->arr[q->front];
}

Data peek(que *q){
	return  q->arr[(q->front + 1) % q->queSize];
}

int main(int argc, char *argv[]){

	que q;
	Data item;
	init(&q,5);

	while(!isfull(&q)){

		scanf("%d",&item);
		enque(&q,item);
	}
	while(!isempty(&q)){
		printf("%d\n",deque(&q));
	}

	free(q.arr);



	return 0;
}
