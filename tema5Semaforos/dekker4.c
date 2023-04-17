#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int cuenta = 0;
int estado[2]; 
int n = 1000000000;

void * ingresar(void * args){
	estado[0] = 1;
	while(estado[1] == 1){
		estado[0] = 0;
		sleep(1);
		estado[0] = 1;
	}
	for(int i = 0; i < n; i++){
			cuenta++;
		}
	estado[0] = 0;
	pthread_exit(0);
}

void * retirar(void * args){
	estado[1] = 1;
	while(estado[0] == 1){
		estado[1] = 0;
		sleep(1);
		estado[1] = 1;
	}
	for(int i = 0; i < n; i++){
			cuenta--;
		}
	estado[1] = 0;
	pthread_exit(0);
}

void * main(void * args){
	pthread_t hilos[2];
	
	pthread_create(&hilos[0], NULL, ingresar, NULL);
	pthread_create(&hilos[1], NULL, retirar, NULL);
	
	pthread_join(hilos[0], NULL);
	pthread_join(hilos[1], NULL);
	
	printf("%d\n", cuenta);
}
