#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>


/*
Para ello, suponga que tiene cinco huecos sobre los que puede producir e inicialmente no tiene
datos para consumir. Los huecos y datos se implementarán a través de semáforos.
Además, tendrá dos tipos de hilos: productores y consumidores.
Los productores están asociados a la función producir (ejecutada cada segundo) y los
consumidores a la función consumir (ejecutada cada cinco segundos), que gestionarán los
huecos y datos de forma adecuada para cada caso, a través de las operaciones wait y signal. En
total, habrá veinte productores y un consumidor.
Tenga en cuenta que debe mostrar por pantalla el número del productor o consumidor y los
elementos que contiene el buffer.
*/


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
		printf("soy el consumidor y el buffer tiene %d elementos\n", n_elementos);
		fflush(stdout);
		sem_post(&mutex);
		//printf("soy el consumidor y el buffer tiene %d elementos\n", n_elementos);
		//fflush(stdout);
		sem_post(&productor);
		sleep(1);
		
	}
}

void * productores(void * args){
	sem_wait(&productor);
	sem_wait(&mutex);
	n_elementos++;
	printf("soy el productor %d y el buffer tiene %d elementos\n", *(int*)args, n_elementos);
	fflush(stdout);
	sem_post(&mutex);
	//printf("soy el productor %d y el buffer tiene %d elementos\n", *(int*)args, n_elementos);
	//fflush(stdout);
	sem_post(&consumidor);
	
}


void main(){
	sem_init(&productor, 0, 5);
	sem_init(&consumidor, 0, 0);
	sem_init(&mutex, 0, 1);
	
	pthread_t consumidor;
	pthread_t productor[20];
	
	pthread_create(&consumidor, NULL, consumidores, NULL);	
	
	int pos_array[20];
	for(int i = 0; i<20; i++){
		pos_array[i] = i;
	}
	
	for(int i = 0; i<20; i++){
		pthread_create(&productor[i], NULL, productores, &pos_array[i]);
	}
	pthread_join(consumidor, NULL);
	
}



