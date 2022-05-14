#include <stdio.h>
#include <stdlib.h>
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
	q->front = 0;
	q->rear = 0;
	q->queSize = max_size;
	q->arr = (Data*)malloc(sizeof(Data) * queSize);
}

int isfull(que *q){
	return q->front == q->rear;
}

int isempty(que *q){
	return ((q->rear + 1) % q->queSize == q->front);
}

void enque(que *q, int item){
	if(isfull(q)){
		printf("Full\n");
		return;
	}
	q->rear = (q->rear + 1 ) % q->queSize;
	q->arr[q->rear] = item;
}

Data deque(que *q){
	if(isempty(q)){
		printf("Empty\n");
		return 0;
	}
	q->front = (q->front + 1) % q->queSize;
	return q->arr[q->front];
}



int main(int argc, char *argv[]){

	que q;
	init(&q,4);

	enque(&


	return 0;
}
