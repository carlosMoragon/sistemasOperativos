#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

/*
Ejercicio 3. Explique los parámetros de la función pthread_create()
y cuál es el resultado del programa.
*/

void * process(void * args){
	printf("%s",(char *)args);
	fflush(stdout);
	pthread_exit(0);
}

int main(void){
	pthread_t th_a,th_b; // Variable tipo thread
	pthread_create(&th_a, NULL, process, "Hello");
	pthread_create(&th_b, NULL, process, "World");
	sleep(1);
}


/*

Los parametro de la función pthread_create() son:
	La dirección del hilo que va a realizar el proceso
	NULL para que tome las prioridades que asigne el sistema operativo por defecto.
	La dirección del metodo que va a ejecutar dicho hilo
	Los parametros del metodo que va a ejecutar dicho hilo
	
La salida del programa será: HelloWorld o WorldHello. No podemos saber que hilo se ejecutará antes.

*/
