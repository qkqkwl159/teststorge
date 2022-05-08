#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void quickSort(char arr[], int L, int R){
	int left = L, right = R;
	char pivot = arr[(L + R) / 2];
  char temp[5];
	do
	{
		printf("heelo\n");
		while(strcmp(&pivot,&arr[left]))
			left++;
		while(strcmp(&arr[right],&pivot))
			right--;
		if(left <= right){
			strcpy(temp,&arr[left]);
			strcpy(&arr[left],&arr[right]);
			strcpy(&arr[right],temp);
			left++;
			right--;
		}
	}while (left<=right);

	if(L < right)
		quickSort(arr, L, right);
	if(left < R)
		quickSort(arr, left, R);
}


int main(void){


	char str[20];
	printf("arr : ");
	scanf("%[^\n]s",str);

	quickSort(str, 0,20-1);

	for(int i=0;i<strlen(str);i++){
		printf("%c",str[i]);
	}
	

	return 0;
}
