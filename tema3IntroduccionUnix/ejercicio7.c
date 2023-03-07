#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>

#define VUELTAS 100000000000

/*
Modifica el siguiente código para que el proceso
termine al recibir la señal SIGINT (o al pulsar Ctrl + C en el teclado)
y se muestre el mensaje: “Saliendo del programa al recibir la señal
SIGINT”.
*/

void Salir(int sig){

	switch(sig){
		case(SIGINT):
			printf("Saliendo del programa al recibir la señal SIGINT\n");
			//exit(EXIT_SUCCESS);
			exit(0);
			break;	
	}
}

void main (void){
	
	signal(SIGINT, Salir);
	for(int i= 0; i<VUELTAS; i++){} //Esto es para q tengamos tiempo de meter la señal
	printf("Saliendo del programa sin recibir la señal\n");
	//exit(EXIT_SUCCESS);
	exit(0);
}
