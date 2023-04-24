#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>

sem_t tenedor[5];
sem_t comedor;

void * filosofo(void * i){
	sem_wait(&comedor);
	sem_wait(&tenedor[*(int*)i]);
	sem_wait(&tenedor[(*(int*)i+1) % 5]);
	printf("soy el filosofo %d y estoy comiendo\n", *(int*)i);
	fflush(stdout);
	sleep(2);
	//printf("soy el filosofo %d y los he soltado\n", *(int*)i);
	//fflush(stdout);
	sem_post(&tenedor[(*(int*)i+1) % 5]);
	sem_post(&tenedor[*(int*)i]);
	sem_post(&comedor);
	
}


void main(){
	for(int i = 0; i<5; i++){
		sem_init(&tenedor[i], 0, 1);
	}
	
	sem_init(&comedor, 0, 4);
	
	pthread_t filosofos[5];
	
	int pos_array[5];
	for(int i = 0; i<5; i++){
		pos_array[i] = i;
	}
	
	for(int i = 0; i<5; i++){
		pthread_create(&filosofos[i], NULL, filosofo, &pos_array[i]);
	}
	for(int i = 0; i<5; i++){
		pthread_join(filosofos[i], NULL);
	}
	
}

