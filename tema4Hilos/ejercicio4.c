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
	printf("SOY EL HILO %d\n", *(int *) args);
	fflush(stdout);
	pthread_exit(0);
}

int main(){
	pthread_t arrayPunteros[8];
	for(int i=0; i < 8; i++){
		pthread_create(&(arrayPunteros[i]), NULL, process, &i);
		sleep(1);
		
	}

}

/*
Los mensajes aparecen en orden del 0-7. Esto se debe a que se estan creando en orden con un tiempo de espera de 1 segundo, por lo que a cada hilo le da tiempo a ejecutar su funcionalidad asignada
antes de que se cree otro hilo.

*/


