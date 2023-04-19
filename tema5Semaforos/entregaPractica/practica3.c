#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>

sem_t max_sofa;
sem_t max_capacidad;
sem_t silla_barbero;
sem_t cortando;
sem_t peluquero;

void * cortar(void * args){

	//while(1){
	for(int i = 0; i<50; i++){
		sem_wait(&peluquero);
		//CORTARLE EL PELO
		printf("LE ESTOY CORTANDO EL PELO\n");
		fflush(stdout);
		sleep(1);
		printf("CORTADO\n");
		fflush(stdout);
		sem_post(&cortando);
		
		
		
		//sleep(3);
	}
}

void * cliente(void * args){
	sem_wait(&max_capacidad);
	//Esta en el local
	printf("EN EL LOCAL: %d\n", *(int*)args);
	fflush(stdout);
	//aforo++;
	sem_wait(&max_sofa);
	printf("EN EL SOFA: %d\n", *(int*)args);
	fflush(stdout);
	//Esta en el sofa
	sem_post(&max_capacidad);
	
	sem_wait(&silla_barbero);
	printf("EN LA SILLA: %d\n", *(int*)args);
	fflush(stdout);
	//DESPERTAR AL BARBERO -> signal(peluquero);
	sem_post(&max_sofa);
	
	sem_post(&peluquero);
	//Esta en sillon
	sem_wait(&cortando);
	//Se lo esta cortando
	printf("CORTE CR7: %d\n", *(int*)args);
	fflush(stdout);
	sem_post(&silla_barbero);
	
	
}


void main(){
	sem_init(&max_capacidad, 0, 20);
	sem_init(&max_sofa, 0, 5);
	sem_init(&silla_barbero, 0, 1);
	sem_init(&cortando, 0, 0);
	sem_init(&peluquero, 0, 0);

	
	pthread_t peluquero;
	pthread_t clientes[50];
	int pos_array[50];
	
	for(int i = 0; i<50; i++){
		pos_array[i] = i;
	}
	pthread_create(&peluquero, NULL, cortar, NULL);	
	
	for(int i = 0; i<50; i++){
		pthread_create(&clientes[i], NULL, cliente, &pos_array[i]);
		
	}
	pthread_join(peluquero, NULL);
	
}


