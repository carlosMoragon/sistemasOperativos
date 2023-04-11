#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int cuenta = 0;

void * suma(void * args){
	for(int i= 0; i<100000; i++){
		cuenta++; //seccion critica
	}
}

void * resta(void * args){
	for(int i= 0; i<100000; i++){
		cuenta--; //seccion critica
	}
}


void main(){
	pthread_t hilos[2];
	
	pthread_create(&hilos[0], NULL, suma, NULL);
	pthread_create(&hilos[1], NULL, resta, NULL);
	
	printf("%d\n", cuenta);
	
}
