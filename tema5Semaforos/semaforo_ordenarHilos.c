#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>

sem_t semaforo;

void * proceso1(void * args){
	printf("Hello");
	sem_post(&semaforo);
	pthread_exit(0);
}

void * proceso2(void * args){
	sem_wait(&semaforo);
	printf("World\n");
	pthread_exit(0);
}

void main(){
	sem_init(&semaforo, 0, 0);
	pthread_t hilos[2];
	
	pthread_create(&hilos[0], NULL, proceso1, NULL);
	pthread_create(&hilos[1], NULL, proceso2, NULL);
//	sleep(1);
	pthread_join(hilos[0], NULL);
	pthread_join(hilos[1], NULL);
	
}
