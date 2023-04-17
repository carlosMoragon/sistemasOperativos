#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/*
Ejercicio 1. Cree un hilo que ejecute una función que sume una
unidad a una variable y cree otro hilo que reste una unidad a esa
misma variable. Ejecute dichas operaciones 100.000 veces de
forma concurrente e imprima el resultado.

¿Obtiene siempre el valor inicial de la variable al ejecutarlo varias veces?
*/

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

/*
No se obtiene el valor inicial de la variable al ejecutarlo varias veces, esto se debe a que el resultado depende del orden en el que se ejecutan las instrucciones de cada hilo, sucediendo una condición de carrera.


*/
