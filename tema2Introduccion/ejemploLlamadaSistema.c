#include <stdio.h>
#include <fcntl.h>

char name[] = "archivo.txt";

int main(){
	//Si te devuelve -1 -> la llamada al sistema no se ha podido hacer.
	
	int fd;
	fd = creat(name, 0666); //llamada al sistema para crear un fichero
	//creat(nombre, permisos)
	return 0;
}
