#include <stdio.h>

void func(){
	
	pthread_mutex_lock(&lock);


	if(condition == 1){
		//unlock을 해놓지않고 return한다면 DeadLock될수 있다.
		// pthread_mutex_unlock(&lock);
		return;
	}

	pthread_mutex_unlock(&lock);

}
