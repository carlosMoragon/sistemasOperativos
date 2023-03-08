#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <wait.h>
#include <unistd.h>

void main(int argc, char *argv[]){
	char contenido;
	int num = 0;
	if(argc==3){
	
		int fd = open(argv[1], O_RDWR, 0666);
		
		while(read(fd,&contenido, 1)){
			if(contenido == (argv[2])[0]){
			 num++;
			}
		}
		
		char mensaje[100];
		sprintf(mensaje,"El caracter %s se repite %d\n",argv[2],num);
		write(1,&mensaje, strlen(mensaje));
	
	
	}else printf("Mala ejecución del programa. Ponga los parametros necesarios.\n");
}
