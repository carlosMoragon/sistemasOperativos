#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>

sem_t mutex;

void * proceso(void * args){
	sem_wait(&mutex);
	printf("%s ", (char *)args);
	sem_post(&mutex);
}

void main(){
	sem_init(&mutex, 0, 1);
	pthread_t hilos[2];
	
	pthread_create(&hilos[0], NULL, proceso, "Hello");
	pthread_create(&hilos[1], NULL, proceso, "World");
//	sleep(1);
	pthread_join(hilos[0], NULL);
	pthread_join(hilos[1], NULL);
	
}
