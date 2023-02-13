#include <stdio.h>
#include <stdlib.h>

//esto una macro:
#define suma(n, m) n + m
void main(int argc, char *argv[]){
	
	printf("%d\n", suma(2, 4));
	
	/*Asignación dinamica de memoria:
	malloc -> asignar espacion en memoria en tiempo de ejecución
	free liberar espacio de memoria en tiempo de ejecución.
	sizeof(operando) -> nº de bytes que ocupa la variable.
	*/
	
	int i;
	float x;
	double d;
	char c;
	printf("Entero: %ld\n", sizeof(i));
	printf("Float: %ld\n", sizeof(x));
	printf("Double: %ld\n", sizeof(d));
	printf("Char: %ld\n", sizeof(c));
	
	//para reservar en memoria 10 variables de tipo int
	int* ptr = (int*) malloc(10*sizeof(int));
	
	if(ptr == NULL)
	printf("error");
	else
	printf("MEmoria asignada");
	
	//liberamos el espacio en memoria reservado.
	free(ptr);
	
	
}
