#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int cuenta = 0;
int turno = 0;

void * suma(void * args){
	while(turno != 0) //Espera activa
	for(int i = 0; i<100000; i++)cuenta++; //seccion critica
	turno = 1;
}

void * resta(void * args){
	while(turno != 1) //Espera activa
	for(int i = 0; i<100000; i++)cuenta--; //seccion critica
	turno = 0;
}


void main(){
	pthread_t hilos[2];
	
	pthread_create(&hilos[1], NULL, suma, NULL);
	pthread_create(&hilos[2], NULL, resta, NULL);
	
	printf("%d\n", cuenta);
	
}
