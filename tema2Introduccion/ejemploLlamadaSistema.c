#include <stdio.h>
#include <fcntl.h>

char name[] = "archivo.txt";

int main(){
	//Si te devuelve -1 -> la llamada al sistema no se ha podido hacer.
	
	int fd;
	fd = creat(name, 0666); //llamada al sistema para crear un fichero
	//creat(nombre, permisos) -> al tener la umask = 0002 -> la última terna se sobre escribe en 010.
	printf("%d\n", fd);
	return 0;
}
