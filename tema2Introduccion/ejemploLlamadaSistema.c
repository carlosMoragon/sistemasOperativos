#include <stdio.h>
#include <fcntl.h>

char name[] = "archivo.txt";

int main(){
	//Si te devuelve -1 -> la llamada al sistema no se ha podido hacer.
	
	int fd;//descriptor de fichero
	fd = creat(name, 0666); //llamada al sistema para crear un fichero
	//creat(path/nombre, permisos) -> al tener la umask = 0002 -> la última terna se sobre escribe en 010.
	
	//otro ejemplo:
	//fd = open ("file.txt", O_CREAT|O_RDWR, 0666);
	//write(fd, mensaje, strlen(mensaje)) -> mensaje es un puntero a la variable del contenido
	//read(fd, &c, 1)
	printf("%d\n", fd);
	return 0;
}
