#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>

sem_t productor;
sem_t consumidor;
sem_t mutex;

int n_elementos = 0;

void * consumidores(void * args){
	int consumidos = 0;
	while(consumidos != 20){
		sem_wait(&consumidor);
		sem_wait(&mutex);
		n_elementos--;
		consumidos++;
		sem_post(&mutex);
		printf("soy el consumidor\n");
		fflush(stdout);
		sem_post(&productor);
		sleep(1);
		
	}
}

void * productores(void * args){
	sem_wait(&productor);
	sem_wait(&mutex);
	n_elementos++;
	sem_post(&mutex);
	printf("soy el productor %d\n", *(int*)args);
	fflush(stdout);
	sem_post(&consumidor);
	
}


void main(){
	sem_init(&productor, 0, 5);
	sem_init(&consumidor, 0, 0);
	sem_init(&mutex, 0, 1);
	
	pthread_t consumidor;
	pthread_t productor[20];
	
	pthread_create(&consumidor, NULL, consumidores, NULL);	
	
	for(int i = 0; i<20; i++){
		pthread_create(&productor[i], NULL, productores, &i);
		pthread_join(productor[i], NULL);
		
	}
	
}


