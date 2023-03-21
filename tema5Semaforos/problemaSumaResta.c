#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int cuenta = 0;
//int varBool = 0;

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

/*
void * suma(void * args){
	while(varBool); //Espera activa
	cuenta++; //seccion critica
	varBool = 1;
}

void * resta(void * args){
	while(varBool); //Espera activa
	cuenta--; //seccion critica
	varBool = 0;
}

*/
void main(){
	pthread_t hilos[2];
	
	pthread_create(&hilos[1], NULL, suma, NULL);
	pthread_create(&hilos[2], NULL, resta, NULL);
	
	printf("%d\n", cuenta);
	
}
