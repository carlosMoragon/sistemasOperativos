#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>

#define VUELTAS 100000000000

/*

SIG_DFL -> para restaurar su opcion por defecto
SIG_IGN -> para ignorar la señal

*/

void Salir(int sig){

	switch(sig){
		case(SIGTERM):
			printf("Saliendo del programa al recibir la señal SIGTERM\n");
			//exit(EXIT_SUCCESS);
			exit(0);
	}
}

void main (void){
	
	signal(SIGTERM, Salir); //Si recibimos la señal sigterm se ejecuta la función salir
	signal(SIGTERM, SIG_IGN); //PARA IGNORAR LA SEÑAL ->siempre se imprime -> Saliendo del programa sin recibir la señal
	
	
	for(int i= 0; i<VUELTAS; i++){} //Esto es para q tengamos tiempo de meter la señal
	printf("Saliendo del programa sin recibir la señal\n");
	//exit(EXIT_SUCCESS);
	exit(0);
}
