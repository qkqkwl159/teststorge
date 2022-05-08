#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	
	int strcnt, lenth;

	scanf("%d",&strcnt);
	scanf("%d",&lenth);

	char **strArr = (char**)malloc(sizeof(char*) * strcnt);

	for(int i = 0; i < strcnt; i++){
		char *str = (char*)malloc(sizeof(char) * lenth);
		
		fgets(str,lenth,stdin);
		strArr[i] = str;
		printf("i : %d \n",i);
	}
		
	for(int i = 0; i < strcnt; i++){
		printf("%s\n",strArr[i]);
		free(strArr[i]);
	}
	free(strArr);
		

	return 0;
}
