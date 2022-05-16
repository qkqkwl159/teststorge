#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

char *stack[MAX_SIZE];
int top;

void init(){
	top = -1;
}

void push(char *item){
	stack[++top] = item;
}
		
char *pop(){
	if(top == -1){
		printf("Empty!\n");
		return NULL;
	}
	return stack[top--];
}


int main(void){
	init();
	char* str = "1234";

	push(str);
	printf("%s\n",pop());


	return 0;
}
