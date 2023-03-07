#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


/*
Ejercicio 2. Escriba un programa que cree un fichero de texto y un
proceso hijo. Si se trata del proceso hijo escriba un carácter en el
fichero (p. ej. ‘1’) y si se trata del proceso padre escriba otro
carácter (p. ej. ‘2’). Permita que se alternen al escribir en el fichero
y escriba un total de 20 caracteres. -NUEVO
*/

void main(){
	int fd = open ("fichero_ej1.txt", O_CREAT|O_RDWR, 0666);
	
	pid_t pid = fork();
	for(int i = 0; i<20; i++){
		if(pid != 0)
			write(fd, "1", 1);
		else{
			write(fd, "2", 1);
		}
	
	}
	
	while(wait(NULL) > 0);

}

/*
Parece que no se alternan por que son solo 20 caracteres.
*/
