#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int cuenta = 0;
int estado[2] = {0,0};

void * suma(void * args){
	estado[0] = 1;
	while(estado[1]);
	

	
	for(int i = 0; i<100000; i++)cuenta++;
	
	estado[0] = 0;
	
	pthread_exit(0);
}

void * resta(void * args){
	estado[1] = 1;
	while(estado[1]);	
	
	for(int i = 0; i<100000; i++)cuenta--;
	
	estado[1] = 0;
	
	pthread_exit(0);
}

void main(){
	pthread_t hilos[2];
	
	pthread_create(&hilos[0], NULL, suma, NULL);
	pthread_create(&hilos[1], NULL, resta, NULL);
	//sleep(1);
	pthread_join(hilos[0], NULL);
	pthread_join(hilos[1], NULL);
	printf("%d\n", cuenta);
	
}
