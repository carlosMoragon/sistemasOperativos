#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>


void main(){
	char frase[] = "Hola Mundo";
	char contenido;
	int fd = open ("archivo.txt", O_CREAT|O_RDWR, 0666); //abrimos el fichero. open(nombre, crear o permisos de lectura y escritura, permisos del fichero);
	
	write(fd, frase, strlen(frase)); //para escribir la frase
	lseek(fd, 0, SEEK_SET); //para mover el puntero al inicio del fichero.
	//read(fd, &contenido, 1); //para leer un caracter.
	//printf("%c\n", contenido);
	
	while(read(fd, &contenido, 1)){
		write(1, &contenido, 1);
		sleep(1);
	}
	
}
