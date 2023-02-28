#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>

#define VUELTAS 100000000000

void Salir(int sig){

	switch(sig){
		case(SIGTERM):
			printf("Saliendo del programa al recibir la señal\n");
			exit(EXIT_SUCCESS);
			break;
	}
}

void main (void){

	for(int i= 0; i<VUELTAS; i++){}
	printf("Saliendo del programa sin recibir la señal\n");
	exit(EXIT_SUCCESS);
}
