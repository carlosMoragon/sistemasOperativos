#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define TAMANO 1024

char buf[TAMANO];

static void error(char* mensaje) {
	 write(2, mensaje, strlen(mensaje)); 
	 exit(1);
}

/*
static void error(char* mensaje) { 
	fprintf(stderr, "%s", mensaje); 
	exit(1);
}*/

int main(int argc, char* argv[]) {

	int leidos, escritos, origen, destino;
	
	if (argc!=3)
		error("Error en argumentos\n");
		
	if ((origen = open(argv[1], O_RDONLY)) < 0)
		error("Error en origen\n");
		
	if ((destino = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0666)) < 0)
		error("Error en destino\n");
		
	while ((leidos = read(origen, buf, TAMANO)) > 0) {
	
		if ((escritos = write(destino, buf, leidos)) < 0) 
			error("Error en escritura\n");
			
	}
	
	if (leidos < 0)
		error("Error en lectura\n");
		
	close(origen);
	close(destino);
	exit(0);
}

/*
Ejercicio1:

openat(AT_FDCWD, "prueba.txt", O_RDONLY) = 3
openat(AT_FDCWD, "prueba_copia.txt", O_WRONLY|O_CREAT|O_TRUNC, 0666) = 4
read(3, "HELLO WORLD\n", 1024)          = 12
write(4, "HELLO WORLD\n", 12)           = 12
read(3, "", 1024)                       = 0
close(3)                                = 0
close(4)                                = 0


Se puede ver las llamadas al sistema open, y lee con 'read' en el bucle devolviendo 1, debido a que hay contenido, y lo escribe con la llamada al sistema 'write',
vuelve ha leer en el bucle con la llamada 'read', pero al haber terminado devuelve 0, y se sale del bucle, haciendo 2 llamadas al sistema 'close', cerrando los ficheros.

Ejercicio2:

No cambian las llamadas al sistema, debido que 'fprintf' es una llamada de alto nivel que implementa una llamada al sistema 'write', y al imprimir el contenido por la salida estandar, no tiene que hacer las llamadas al sistema de apertura de un fichero.


*/



