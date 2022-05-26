#include <stdio.h>
#include <stdlib.h>

void add(int* List){
	List[0] = 1;
	List[1] = 2;
	List[2] = 3;
}

void insertLast(int List[],int value){

	int arr_count = sizeof(List) / sizeof(int);
	List[arr_count -1] = value;	

}


int main(int argc, char* argv[]){

	int List[5] ={0,};
	insertLast(List,22);

	for(int i= 0; i<5; i++){
		printf("%d \n", List[i]);
	}

	return 0;
}
