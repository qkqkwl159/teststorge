#include <stdio.h>
#include <stdlib.h>

typedef struct num{
	int value;
	struct num *next;
}num;

void print_list(num *n){
	num *curr = NULL;	
	for(curr = n;curr !=NULL; curr = curr->next){
		printf("%d -> ",n->value);
	}
}

void free_list(num *n){
	num *curr = NULL;	
	for(curr = n;curr !=NULL; curr = curr->next){
		free(n);
	}
}
int main (int argc,char* argv[]){

	num *n1 = (num*)malloc(sizeof(num) * 1);
	n1->value = 10;
	num *n2 = (num*)malloc(sizeof(num) * 1);
	n1->next = n2;
	n2->value = 20;
	num *n3 = (num*)malloc(sizeof(num) * 1);
	n2->next = n3;
	n3->value = 30;
	n3->next = NULL;
	
	print_list(n1);
	free_list(n1);

	return 0;
}
