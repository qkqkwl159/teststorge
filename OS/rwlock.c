#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>



//,data 를 업데이트 받을 Array
char* week[5] = {"Mon","Tue","Wed","Thu","Fri"};
char* DB[5] = {NULL, };
//critical section에 동시에 접근하지 못하게 하기위한 mutex
pthread_mutex_t mutex;
//함수 사이에서 critical section에 접근할때 서로 signal을 보내기위한 condition check
pthread_cond_t cond;

//reader들의 순서를 체크하기위한 count
int count = 0;
//Data를 업데이트하거나 읽기위한 index
int idx= 0;

//writer가  DB에 데이터를 쓸때 아무도 DB에 접근해서는 안된다. 같은 writer도 signal을 보냇을때 접근할수 있다.
void *writer(void *arg){
	while(1){
		//count또한 critical section이기에 값을 보호하기위하여 lock을 한다. 
		pthread_mutex_lock(&mutex);
		//reader의 순서 체크
		count++;
		//Reader가 첫번째 순서로 접근했을때 signal을 준다. 
		if(count == 1)
			pthread_cond_signal(&cond);
		//count unlock
		pthread_mutex_unlock(&mutex);

		//DB value Update
		if(idx == 4)
			idx = idx % 4;
		DB[idx] = week[idx++];
		
		
		//count또한 critical section이기에 값을 보호하기위하여 lock을 한다. 
		pthread_mutex_lock(&mutex);
		count--;
		//last Reader , wait -> Reader
		if(count == 0)
			pthread_cond_wait(&cond,&mutex);
		//count unlock
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
}

//reader는 동시에 DB에 접근하여 값을 읽을수 있다. 
void* reader(void *arg){
	while(1){

		pthread_cond_signal(&cond);
		int readIdx = (int*)arg + idx;

		if(readIdx >= 4)
			readIdx = readIdx % 4;
		printf("Data : %s\n", DB[readIdx]);
		pthread_cond_wait(&cond,&mutex);
	}
}


int main(int argc, char* argv[]){

	pthread_t writer_th,reader1_th,reader2_th,reader3_th, reader4_th;

	pthread_mutex_init(&mutex,NULL);
	pthread_cond_init(&cond,NULL);
	pthread_create(&writer_th,NULL,writer,NULL);
	pthread_create(&reader1_th,NULL,reader,1);
	pthread_create(&reader2_th,NULL,reader,2);
	pthread_create(&reader3_th,NULL,reader,3);
	pthread_create(&reader4_th,NULL,reader,4);

	pthread_join(reader1_th,NULL);
	pthread_join(reader2_th,NULL);
	pthread_join(reader3_th,NULL);
	pthread_join(reader4_th,NULL);


	return 0;
}
