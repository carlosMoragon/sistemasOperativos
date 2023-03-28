#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>

sem_t mutex;

int cuenta = 0;


void * suma(void * args){
	
	for(int i= 0; i<100000; i++){
		sem_wait(&mutex);
		cuenta++; //seccion critica
		sem_post(&mutex);
	}
	
}

void * resta(void * args){

	for(int i= 0; i<100000; i++){
		sem_wait(&mutex);
		cuenta--; //seccion critica
		sem_post(&mutex);
	}

}


void main(){
	sem_init(&mutex, 0, 1);
	pthread_t hilos[2];
	
	pthread_create(&hilos[0], NULL, suma, NULL);
	pthread_create(&hilos[1], NULL, resta, NULL);
	sleep(1);
	printf("%d\n", cuenta);
	
}
