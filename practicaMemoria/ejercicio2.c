#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

int dato;
int *dir;
long *dir2;

void nolee(int s) {
	printf(" no legible\n");
	sleep(1000);
	exit(0);
}

void noescribe(int s) {
	printf(" no escribible\n");
	sleep(1000);
	exit(0);
}

void escribe(char* texto, void *dir) {
	printf ("Dirección de %-4s = 0x%lx\n", texto,(long)dir);
}

int main(int argc, char *argv[]) {
	int A;
	escribe("A", &A);
	//escribe("main", &main);
	dir = (unsigned int*)&A;
	//dir = (unsigned int*)&main;
	printf ("Probando la dirección virtual 0x%lx\n", (long)dir);
	signal(SIGSEGV, nolee);
	dato = *dir;	//SE intenta leer en la dirección de memoria del main, y como tiene permisos de lectura es legible.
	printf(" legible\n");
	signal(SIGSEGV, noescribe);
	*dir = dato; //Se intenta escribir en la dirección de memoria del main, y como solo tiene permisos de lectura y ejecución, y no de escritura, el SSOO nos manda una señal SIGSEGV
	printf(" escribible\n");
	sleep(1000);
	exit(0);
}

/*
SALIDA:
1º caso:

Dirección de main = 0x563128bd625a
Probando la dirección virtual 0x563128bd625a
 legible
 no escribible

Explicación:
Se intenta leer en la dirección de memoria de main, la cual tiene permisos de lectura y ejecución, por lo que al leerlo no salta ningún error. Después intenta escribir en la dirección de memoria de main, pero al no tener permisos de escritura, el sistema operativo manda una señal SIGSERV al proceso main, imprimiendo "no escribible".

2º caso:
Dirección de A    = 0x7ffec612aa74
Probando la dirección virtual 0x7ffec612aa74
 legible
 escribible

Se intenta leer y escribir en una dirección de memoria de una variable local, la cual está contenido en el Stack, el cual tiene permisos de escritura y de lectura, por lo que no hay ningún problema en su ejecución.

*/

