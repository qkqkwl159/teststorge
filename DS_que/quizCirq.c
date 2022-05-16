#include <stdio.h>
#include <stdlib.h>
#define DEBUG
#include "log.h"

typedef char* Data;
typedef struct{
	int front;
	int rear;
	int que_size;
	Data *arr;
}que;

void init(que *q, int size){
	q->front = 0;
	q->rear = 0;
	q->que_size = size+1;
	q->arr = (Data*)malloc(sizeof(Data) * q->que_size);
}

int is_full(que *q){
	return ((q->rear + 1) % q->que_size == q->front);
}

int is_empty(que *q){
	return (q->rear == q->front);
}

void enqueue(que *q,Data item){
	if(is_full(q)){
		printf("enqueue Error!\n");
		return;
	}
	q->rear = (q->rear + 1 ) % q->que_size;
	q->arr[q->rear] = item;

}

Data dequeue(que *q){
	if(is_empty(q)){
		printf("dequeue Error!\n");
		return NULL;
	}
	q->front = (q->front + 1) % q->que_size;
	return q->arr[q->front];
}

int main(int argc, char* argv[]){

	que *s = (que*)malloc(sizeof(que));
	init(s,3);

	enqueue(s,"good");
	enqueue(s,"world");
	enqueue(s,"Hello");
	enqueue(s,"Hi");

	while(!is_empty(s)){
		printf("%s\n",dequeue(s));
	}
	dequeue(s);
	free(s);

	return 0;
}
