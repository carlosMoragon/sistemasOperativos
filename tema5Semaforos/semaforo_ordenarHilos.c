#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>

sem_t mutex;

void * proceso1(void * args){
	printf("%s ", (char *)args);
	sem_post(&mutex);
	pthread_exit(0);
}

void * proceso2(void * args){
	sem_wait(&mutex);
	printf("%s ", (char *)args);
	pthread_exit(0);
}

void main(){
	sem_init(&mutex, 0, 0);
	pthread_t hilos[2];
	
	pthread_create(&hilos[0], NULL, proceso1, "Hello");
	pthread_create(&hilos[1], NULL, proceso2, "World");
//	sleep(1);
	pthread_join(hilos[0], NULL);
	pthread_join(hilos[1], NULL);
	
}
