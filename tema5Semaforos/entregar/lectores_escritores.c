#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>

sem_t writer;
sem_t mutex;

int readers = 0;

void * escribir(void * args){
	sem_wait(&writer);
	printf("escribir\n");
	fflush(stdout);
	sleep(1);
	printf("Terminado de escribir\n\n");
	fflush(stdout);
	sem_post(&writer);
}

void * leer(void * args){
	
	//PEDIR PERMISO
	sem_wait(&mutex);
	readers++;
	if(readers==1) sem_wait(&writer);
	sem_post(&mutex);
	
	//LEER
	
	printf("leer\n");
	fflush(stdout);
	sleep(1);
	printf("Terminado de leer\n\n");
	fflush(stdout);
	
	//TERMINAR LECTURA
	sem_wait(&mutex);
	readers--;
	if(readers==0) sem_post(&writer);
	sem_post(&mutex);
	
	
	
}


void main(){
	sem_init(&writer, 0, 1);
	sem_init(&mutex, 0, 1);
	
	pthread_t escritor;
	pthread_t lector[20];
	
	pthread_create(&escritor, NULL, escribir, NULL);	
	
	for(int i = 0; i<20; i++){
		pthread_create(&lector[i], NULL, leer, NULL);
		//pthread_join(lector[i], NULL);
		
	}
	pthread_join(escritor, NULL);
	
}
