#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
   
int cnt =0;
pthread_mutex_t mutex;

void* count(void* arg){
	int i;
	char* name = (char*)arg;

	pthread_mutex_lock(&mutex);

	//========Critical Section ========
	cnt = 0;
	for(i =0; i < 10; i++){
		printf("%s cnt : %d\n", name,cnt);
		cnt++;
		usleep(1);
	}
	//========Critical Section ========
	pthread_mutex_unlock(&mutex);
	
}

int main(int argc,char *argv[]){
	pthread_t t1,t2,t3;
	//mutex intialized
	pthread_mutex_init(&mutex,NULL);

	pthread_create(&t1,NULL,count,"Thread1");
	pthread_create(&t2,NULL,count,"Thread2");
	pthread_create(&t3,NULL,count,"Thread3");
	
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);

	pthread_mutex_destroy(&mutex);

	return 0;
}

