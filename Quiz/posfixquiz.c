#include <stdio.h>
//#define DEBUG
#include "log.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//stack 구조체
typedef struct{
	int top;
	int stSize;
	int *data;
}stack;

//스택 초기화 함수
void init(stack *s,int size){
	s->top = -1;
	s->stSize = size;
	s->data = (int*)malloc(sizeof(int) * size);
	LOG("");
}

//stack이 비어있는지 확인
int isempty(stack *s){
	return (s->top == -1);
}

int isfull(stack *s){

	return (s->top == s->stSize);
}
//stack에 푸쉬
void push(stack *s,int item){
	if(isfull(s)){
		printf("Full\n");
		return;
	}
	s->data[++(s->top)] = item;
}

//stack의 top를 pop
int pop(stack *s){
	if(isempty(s)){
		printf("Empty\n");
		return 0;
	}
	return s->data[s->top--];
}

//현재 top의 값을 반환
int istop(stack *s){
	return s->data[s->top];
}

//중위를 후위표기로 변환 하는 함수
//stack 과 중위 표기식, 후위표기식을 매개변수로 받아옴
void inToPos(stack *s,char *infix, char *posfix){
	//posfix에 값을 추가하면 cnt를 증가
	int cnt = 0;
	//infix의 각 문자를 token으로 표현
	char token;
	//infix의 길이만큼 반복
	for(int i = 0; i<strlen(infix); i++){
		LOG(" INFIX[%d] : %c\n",i,infix[i]);
		token = infix[i];
		//연산자일때 
		if( token == '+' || token == '-' || token == '*' || token == '/'){
			LOG("OPERATOR\n");
			//top이 * or /이면 pop값을 posfix에 저장 현재 연산자는 push
			if(istop(s) == '*' || istop(s) == '/'){
				LOG(" TOP IS * \n");
				posfix[cnt++] = pop(s);
				push(s,token);
				continue;
			}
			//현재 연산자를 push
			else{
				LOG("TOP != * OR /  ");
				push(s,token);
			}	
		}
		//token이 숫자일때
		else if(isdigit(token)){
			//posfix에 token을 저장후 cnt증가
			posfix[cnt++] = token;
		}
		//token 닫는 괄호 일때
		else if(token == ')'){
			LOG(" TOKEN ( \n");
			//top이 ( 일때까지 연사자를 pop후 posfix에 저장
			while(!(istop(s) == '(')){
				posfix[cnt++] = pop(s);
			}
			// stack에 남아있는 ( 를 pop
			pop(s);
		}
		//여는 괄호 일때 스택에 push
		else push(s,token);
	}
	//infix 길이만큼 반복이끝나고 스택의 남은 연산자를 pop 하는것
	do{
		posfix[cnt++] = pop(s);
	}while(!isempty(s));
}

//posfix를 계산하는 함수
// stack 과 posfix를 매개변수로 받아옴
int cal(stack *s,char *posfix){
	//posfix의 각 문자를 token에 저장
	char token;
	// char형의 token에 '0'을 빼주어 값은 같으나 int형 value 에 저장
	int value;
	//posfix의 길이만큼 반복
	for(int i = 0; i<strlen(posfix);i++){
		token = posfix[i];	
		//token 이 숫자 일때 
		if(isdigit(token)){
			LOG(" CAL DIGIT : %c ",token);
			// char형의 token에 '0'을 빼주어 값은 같으나 int형 value 에 저장
			value = token - '0';	
			//바꿔준 값을 push
			push(s,value);
		}
		//token 숫자가 아닐때 -> 연산자 일때 
		else{
			//스택의 값을 pop하여 각 변수에 저장
			int pop2 = pop(s);
			int pop1 = pop(s);
			LOG(" POP DATA : 1 %d, 2 %d",pop1,pop2);
			//token의 연산자에 따라 맞는 연산을 실행 단, 연산의 순서를 정확히 해줄것 (- , / 는 순서에 따라 값이 바뀜)
			switch(token){
				case '+': push(s,pop1+pop2); break;
				case '-': push(s,pop1-pop2); break;
				case '/': 
									if(pop2 == 0){//나눠줄 값이 0이라면 오류출력후 종료 
										printf("계산 결과 : 오류 :0으로 나눌수 없습니다.\n"); 
										exit(1);
									}
									push(s,pop1/pop2);
									break;
				case '*': push(s,pop1*pop2); break;
			}
		}

	}
	//마지막에 남은 값을 pop
	return pop(s);
}

int main(int argc , char* argv[]){

	//infix to posfix에 사용할 스택
	stack *operator = (stack*)malloc(sizeof(stack) *10 );
	//cal()에 사용할 스택
	stack *calstack = (stack*)malloc(sizeof(stack) *10 );

	char *infix = (char*)malloc(sizeof(char) * 20);
	char *posfix = (char*)malloc(sizeof(char) * 20);


	//각 스택 초기화
	init(operator,20);
	init(calstack,20);
	LOG("INIT\n");
	//값을 입력 받음 
	scanf("%s",infix);
	//infix = "(5*5)+(2*9)*9";
	printf("infix  = %s \n",infix);

	inToPos(operator,infix,posfix);
	printf("posfix = %s \n",posfix);

	printf("CAL Result : %d\n",cal(calstack,posfix));
	//(3+3)/2 , (3+3)*(4+2)/2
	return 0;
}
