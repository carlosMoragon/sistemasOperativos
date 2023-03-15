#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void * process(void * args){
	for(int i=0; i<3; i++){
		printf("%s\n", (char *) args);
		fflush(stdout);
	}
	pthread_exit(0);
}



void main(){
/*Ejercicio 5. Realiza un programa que cree 3 hilos de ejecución y
cada uno de ellos imprima una letra 3 veces (A, B y C
respectivamente).*/

	pthread_t hilos[3];
	
	pthread_create(&hilos[0], NULL, process, "a");
	pthread_create(&hilos[1], NULL, process, "b");
	pthread_create(&hilos[2], NULL, process, "c");
	sleep(1);

}
