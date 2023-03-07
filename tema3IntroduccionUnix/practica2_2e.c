#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <wait.h>
#include <unistd.h>

void main (int argc, char *argv[]){
	char contenido[500];
	if(argc == 2){
		
		int fd = open(argv[1], O_RDWR, 0666);
		
		while(read(fd, contenido, 1)){
			write(1, contenido, 1);
		}
		close(fd);
		
	}else printf("Mala ejecución del programa. Ponga los parametros necesarios.");
	
}

