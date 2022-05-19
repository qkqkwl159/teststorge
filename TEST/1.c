#include <stdio.h>

void func(int* vlaue){
	*vlaue = 10;
}

int main(int argc, char* argv[]){

	int* loging;
	*loging = 10;
	printf("%d\n",*loging);


	return 0;
}
