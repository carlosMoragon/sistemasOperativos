#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


/*
Ejercicio 4. Realiza un programa que cree 8 hilos de ejecución y
cada uno de ellos imprima: “Soy el hilo X”.
¿En qué orden aparecen los mensajes? Razona tu respuesta
*/

void * process(void * args){
	printf("%s", (char *) args);
	fflush(stdout);
	pthread_exit(0);
}

int main(){
	pthread_t arrayPunteros[8];
	char *string;
	for(int i=0; i < 8; i++){
		sprintf(string, "Soy el hilo %d", i);
		pthread_create(&(arrayPunteros[i]), NULL, process, string);
	}

}

