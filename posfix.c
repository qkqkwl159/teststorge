#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100
char *operator[MAX_SIZE];
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

void push(char *item){
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
char *chr_top(){
	return operator[top];
}
void inToPos(char *infix, char *posfix){
	int priority = 0;
	int cnt=0;
	char *token;
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
	
char *chr_pop(){
	if(isempty()){
		printf("Empty!\n");
		return NULL;
	}
	return operator[top--];
}

char *tokArr[200] = { NULL ,};

void tokenalize(char *posfix){

	int i =0;
	char *temp = strtok(posfix," ");
	while(temp != NULL){
		tokArr[i] = temp;
		i++;
		temp = strtok(NULL," ");
	}
}


void cal(){
	char *token;
	int temp;
	int pop1,pop2,result = 0;
	char *chr_result;
	for(int i = 0; tokArr[i] != NULL;i++){
			token = tokArr[i];
			printf("now token : %s\n\n",token);
			if(isdigit(*tokArr[i])){
				push(token);
				printf("now top ISDIGIT_push: %s \n\n",chr_top());
			}
			else{
				pop1 = atoi(chr_pop());
				pop2 = atoi(chr_pop());
				printf(" pop1 = %d , pop2 = %d \n",pop1,pop2);
				printf("Pre Cal TOP : %s\n\n",chr_top());
				
				switch(*token){
					case '+':
						result = pop2 + pop1;
						sprintf(chr_result,"%d",result);
						printf("%s \n",chr_result);
						printf("now top pre_push: %s \n\n",chr_top());
						push(chr_result);
						printf("now top aft_push : %s \n\n",chr_top());
						break;
						/*
					case '-':
						result = pop2 - pop1;
						sprintf(chr_result,"%d",result);
						printf("%s \n",chr_result);
						push(chr_result);
						*/
						
					case '*':
						result = pop2 * pop1;
						printf("now top result: %s \n\n",chr_top());
						sprintf(chr_result,"%d",result);
						printf("now top sprintf: %s \n\n",chr_top());
						printf("%s \n",chr_result);
						printf("now top pre_push: %s \n\n",chr_top());
						push(chr_result);
						printf("now top aft_push: %s \n\n",chr_top());
						break;
						
						/*
					case '/':
						result = pop2 / pop1;
						sprintf(chr_result,"%d",result);
						printf("%s \n",chr_result);
						push(chr_result);
						*/
				}
			}
	}
}

int main(void){

	char infix[200] = "(5+5*9+5*6)",posfix[200];

	init(20);
	inToPos(infix,posfix);
	printf("infix : %s \nposfix : %s\n",infix,posfix);
	tokenalize(posfix);
	init(20);
	cal();


return 0;
}
