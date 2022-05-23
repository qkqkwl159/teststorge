#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>


pthread_mutex_t mutex;
pthread_cond_t cond;

int data = 0;

void* increase(void *arg){
	while(1){
		pthread_mutex_lock(&mutex);
		data++;
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
}

void* printData(void *arg){
	while(1){
		pthread_mutex_lock(&mutex);
		pthread_cond_wait(&cond,&mutex);
		printf("Data : %d\n",data);
		pthread_mutex_unlock(&mutex);
	}
}

int main(int argc,char *argv[]){

	pthread_t thread1, thread2, thread3;

	pthread_mutex_init(&mutex,NULL);
	pthread_cond_init(&cond,NULL);
	pthread_create(&thread1, NULL, increase,NULL);
	pthread_create(&thread2, NULL, printData,NULL);
	pthread_create(&thread3, NULL, printData,NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);

	return 0;
}

