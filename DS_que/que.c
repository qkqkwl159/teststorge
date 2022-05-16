#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG
#include "log.h"

#define MAX_SIZE 5 

typedef int Data;
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

int empty(que *q){
	return (q->front == q->rear);
}


void enque(que *q, int item){
	q->arr[q->rear++] = item;
}

Data deque(que *q){
	return q->arr[q->front++];
}

Data peek(que *q){
	return q->arr[q->front];
}

int main(int argc, char *argv[]){

	que q;
	init(&q);
	enque(&q,20);
	enque(&q,30);
	enque(&q,80);
	enque(&q,70);

	printf("%d\n",deque(&q));
	printf("%d peek\n",peek(&q));
	printf("%d\n",deque(&q));
	printf("%d\n",deque(&q));
	printf("%d\n",deque(&q));
	return 0;
}
