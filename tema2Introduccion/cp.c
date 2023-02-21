#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

void main(int argc, char *argv[]){
	
	if(argc == 3){
		int fd = open(argv[1], O_CREAT|O_RDWR, 0666);
		int fd2 = creat(argv[2], 0666);
		char contenido;
		while(read(fd, &contenido, 1)){
			write(fd2, &contenido, 1);
		}
		
		
	}else
		printf("Error. Error en los parametros al ejecutar el programa");
}


