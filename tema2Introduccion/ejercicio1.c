#include <stdio.h>
#include <fcntl.h>

char name[]="archivo.txt";

int main(){
	int fd;
	fd=creat(name,0666);
	printf("%d\n", fd);
	return 0;
}

/*

Devuelve el numero 3.
Se le asigna el número 3 al file descriptor debido a que los valores del 0 al 2 estan reservados ( 0= input por terminal; 1 = output por terminal; 2 = error).

El fichero archivo.txt se ha creado con los permisos 0662 (-rw-rw-r--), en vez de 0666 como se ha establecido en el método creat, esto se debe a que la umask es 0002, por lo que podemos
rescribir los tres primeros digitos, pero el último se establece un 2 por defecto.


*/
