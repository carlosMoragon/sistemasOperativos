#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>
#define n_clientes 50

/*

capacidad 30 personas
cliente solicita sentarse en una mesa
15 mesas
No mesas libres -> bloqueado en la barra

cliente come en una mesa -> 10 seg
cliente termina -> bloqueado espera la cuenta (la trae el camarero)

restaurante 1 camarero que espera bloqueado a la cuenta -> tarda 5 seg en entregarla

*/
sem_t local;
sem_t mesas;
sem_t sem_camarero;
sem_t cuenta;

void * fcamarero(void * args){
	for(int i = 0; i<n_clientes; i++){
		sem_wait(&sem_camarero); //bloquear al camarero
		printf("La cuenta ahora te la traigo\n");
		fflush(stdout);
		sleep(5);
		sem_post(&cuenta);//traer la cuenta
		printf("La cuenta\n");
	}
	
}

void * cliente(void * args){

	sem_wait(&local);
	printf("Quiero una mesa: %d\n", *(int*)args);
	fflush(stdout);
	sem_wait(&mesas);
	printf("A comer que hay hambre: %d\n", *(int*)args);
	fflush(stdout);
	sleep(10);
	sem_post(&sem_camarero);
	printf("Esperando la cuenta: %d\n", *(int*)args);
	sem_wait(&cuenta);
	printf("Vaya sablazo que me han metido: %d\n", *(int*)args);
	fflush(stdout);
	sem_post(&mesas);
	sem_post(&local);
	
}

void main(){
	sem_init(&local, 0, 30);
	sem_init(&mesas, 0, 15);
	sem_init(&sem_camarero, 0, 0);
	sem_init(&cuenta, 0, 0);
	
	pthread_t clientes[n_clientes];
	pthread_t camarero;
	
	int pos_array[n_clientes];
	for(int i = 0; i<n_clientes; i++){
		pos_array[i] = i;
	}
	
	pthread_create(&camarero, NULL, fcamarero, NULL);
	
	for(int i = 0; i<n_clientes; i++){
		pthread_create(&clientes[i], NULL, cliente, &pos_array[i]);
	}
	pthread_join(camarero, NULL);
	
}

