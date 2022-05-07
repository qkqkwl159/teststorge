#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100
char operator[MAX_SIZE];
int top;
int stack_size;

void init(int size){
	top = -1;
	stack_size = size;
}

int isfull(){
	return (top == stack_size);
}

int isempty(){
	return (top == -1);
}

void push(char item){
	if(isfull()){
		printf(" Full !\n");
		return;
	}
	operator[++top] = item;
}

int pop(){
	if(isempty()){
		printf("Empty!\n");
		return 0;
	}
	return operator[top--];
}

int istop(){
	return operator[top];
}
void inToPos(char *infix, char *posfix){
	int priority = 0;
	int cnt=0;
	char token;
	int continuity = 0;
	for(int i=0; i<strlen(infix);i++){
		token=infix[i];
		if(token == '('){
			continuity =0;
			push(token);	
		}
		else if(token == ')'){
			continuity =0;
			while(istop() != '('){
				if(isempty()){
					printf("infix Error! : '('\n");
					exit(1);
				}
				posfix[cnt++] = ' ';
				posfix[cnt++] = pop();
			}
			pop();	
		}
		else if(token == '+' || token == '-' || token == '/' || token == '*'){
			continuity =0;
			if(istop() == '*' || istop() == '/'){
				posfix[cnt++] = ' ';
				posfix[cnt++] = pop();
				push(token);
				continue;
			}
			if(token == '/' || token == '*'){
				push(token);
			}
			else{
				push(token);
			}
		}
		else{
			if(continuity == 0){
				if(cnt != 0) posfix[cnt++] = ' ';
				posfix[cnt++] = token;
			}
			else{
				posfix[cnt++] = token;
			}
			continuity++;
		}
	}
	do{
		if(istop() == '(') {
			printf("infix Error! : ')'\n");
			exit(1);
		}
		posfix[cnt++] = ' ';
		posfix[cnt++] = pop();
	}while(!isempty());
}
	
int tokenalize(char *posfix){
	operator[0] = '\0';
	int i = 0;
	int cnt = 0;
	char scan;
	char token[20];
	while(i < strlen(posfix)){
		scan = posfix[i];
		
		i++;
	}
	
	return 0;
}


int main(void){


	char infix[200] = "5*(10+20)+5",posfix[200];

	init(20);
	inToPos(infix,posfix);

	tokenalize(posfix);
	printf("infix : %s \nposfix : %s\n",infix,posfix);

return 0; }
